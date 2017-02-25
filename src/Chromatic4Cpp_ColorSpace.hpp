//
//  Chromatic4Cpp_ColorSpace.hpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_ColorSpace_hpp
#define Chromatic4Cpp_ColorSpace_hpp
#import "Chromatic4Cpp_BaseTypes.hpp"
#import "Chromatic4Cpp_HexColor.hpp"
#import "Chromatic4Cpp_DataFrame.hpp"
#import "Chromatic4Cpp_HelperUtils.hpp"


class HEX {
private:
    HexFrame _hexFrame;
    
public:
    HEX() {}
    
    HEX(HexStr hex) {
        Set(hex);
    }
    
    HEX(HexStr hex, ChannelNumMode mode) {
        _hexFrame.channelMode = mode;
        _hexFrame.checkMode   = eHexCheckModeAutoConvert;
        Set(hex);
    }
    
    HEX(HexStr hex, HexCheckMode mode) {
        _hexFrame.checkMode   = mode;
        _hexFrame.channelMode = eChannelNumMode3;
        Set(hex);
    }
    
    HEX(HexStr hex, ChannelNumMode channel, HexCheckMode check) {
        _hexFrame.checkMode   = check;
        _hexFrame.channelMode = channel;
        Set(hex);
    }
    
    HEX(HexFrame& other) {
        SetHexFrame(other);
    }
    
    HEX& Dump() {
        _hexFrame.Dump();
        return *this;
    }
    
    HexStr Get() {
        return _hexFrame.hex.substr(0, _hexFrame.hex.size());
    }
    
    HEX& Set(HexStr hex) {
        switch (_hexFrame.checkMode) {
            case eHexCheckModeAutoConvert:
                _Set(HelperUtils::AutoConvertHexStr(hex));
                break;
            case eHexCheckModeSkipInvalid:
                _Set(HelperUtils::SkipInvalidHexStr(hex));
                break;
            case eHexCheckModeStrictCheck:
                HelperUtils::StrictCheckHexStr(hex);
            default:
                break;
        }
        return *this;
    }
    
    HexFrame GetHexFrame() {
        return _hexFrame.Clone();
    }
    
    HEX& SetHexFrame(HexFrame& other) {
        _hexFrame = other;
        Set(_hexFrame.hex);
        return *this;
    }
    
    ChannelNumMode GetChannelMode() {
        return _hexFrame.channelMode;
    }
    
    HEX& SetChannelMode(ChannelNumMode mode) {
        _hexFrame.channelMode = mode;
        Set(_hexFrame.hex);
        return *this;
    }
    
    HexCheckMode GetCheckMode() {
        return _hexFrame.checkMode;
    }
    
    HEX& SetCheckMode(HexCheckMode mode) {
        _hexFrame.checkMode = mode;
        Set(_hexFrame.hex);
        return *this;
    }
    
    int GetChannelDecNum(HexBit channel) {
        if(channel < 1 || channel > 4) return 0;
        return (int)HelperUtils::Hex2Number(_hexFrame.hex.substr((channel-1)*2, 2));
    }
    
    sRGBFrame RGBFrame() {
        sRGBFrame frame;
        frame.r = GetChannelDecNum(1);
        frame.g = GetChannelDecNum(2);
        frame.b = GetChannelDecNum(3);
        return frame;
    }
    
    sRGBAFrame RGBAFrame() {
        sRGBAFrame frame;
        frame.r = GetChannelDecNum(1);
        frame.g = GetChannelDecNum(2);
        frame.b = GetChannelDecNum(3);
        frame.a = GetChannelDecNum(4);
        return frame;
    }
    
private:
    void _Set(HexStr hex) {
        HelperUtils::AutoFillHexStr(hex, _hexFrame.channelMode, "0");
        _hexFrame.hex = hex;
    }
};
    
    
class RGB {
private:
    HexStr _hex;
    sRGBFrame _frame;
public:
    RGB() {
        sRGBFrame frame = sRGBFrame(0,0,0);
        Set(frame);
    }
    
    RGB(RGBit r, RGBit g, RGBit b, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBFrame frame = sRGBFrame(r,g,b);
        Set(frame);
    }
    
    RGB(HexStr hex, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBFrame frame = HEX(hex).RGBFrame();
        frame.inputMode = mode;
        Set(frame);
    }
    
    RGB(HEX hex, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBFrame frame = hex.RGBFrame();
        frame.inputMode = mode;
        Set(frame);
    }
    
    RGB(sRGBFrame& frame) {
        Set(frame);
    }
    
public:
    int Red()   { return _frame.Red(); }
    int Green() { return _frame.Green(); }
    int Blue()  { return _frame.Blue(); }
    RGB& Red(RGBit r)   { _frame.Red(r); return *this; }
    RGB& Green(RGBit g) { _frame.Green(g); return *this; }
    RGB& Blue(RGBit b)  { _frame.Blue(b); return *this; }
    
    RGB& Set(sRGBFrame& frame) {
        _Set(frame);
        return *this;
    }
    
    RGB& Set(RGBit r, RGBit g, RGBit b) {
        sRGBFrame frame = sRGBFrame(r,g,b);
        return Set(frame);
    }

    sRGBFrame Get() { return _frame.Clone(); }
    
    RGB& Dump() {
        if(_frame.inputMode == eRGBAChannelInputModeFloat)
            _frame.DumpAsFloat();
        else
            _frame.Dump();
        return *this;
    }
    
    RGBAChannelInputMode GetChannelInputMode() {
        return _frame.inputMode;
    }
    
    RGB& SetChannelInputMode(RGBAChannelInputMode mode) {
        _frame.CheckInputMode(mode);
        return *this;
    }
    
    HEX AsHEX() {
        return HEX(HexString());
    }
    
    const HexStr HexString() {
        HexStr ret;
        ret.clear();
        ret.append(HelperUtils::Number2Hex(_frame.Red()));
        ret.append(HelperUtils::Number2Hex(_frame.Green()));
        ret.append(HelperUtils::Number2Hex(_frame.Blue()));
        return ret;
    }
private:
    void _Set(sRGBFrame& frame) {
        frame.CheckInputMode(frame.inputMode);
        _frame = frame;
    }
};
    
//    class RGBA : public RGB {
//    private:
//        static RGBA* _instance;
//        sRGBAFrame _frame;
//    public:
//        static RGBA& Instance() {
//            if(_instance == NULL) {
//                _instance = new RGBA;
//            }
//            return *_instance;
//        };
//        RGBA();
//        RGBA(RGBit, RGBit, RGBit, RGBit, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
//        RGBA(HexStr, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
//        RGBA(HEX, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
//        RGBA(sRGBAFrame&);
//    };
    

struct RGBA;
struct CMYK;
struct HSL;
struct HSV;
struct YUV;
struct LAB;

#endif /* Chromatic4Cpp_ColorSpace_hpp */
