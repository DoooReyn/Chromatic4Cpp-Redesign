//
//  Chromatic4Cpp_HEX.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_HEX_hpp
#define Chromatic4Cpp_HEX_hpp

#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"

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
        frame.inputMode = eRGBAChannelInputModeInteger;
        return frame;
    }
    
    sRGBAFrame RGBAFrame() {
        sRGBAFrame frame;
        frame.r = GetChannelDecNum(1);
        frame.g = GetChannelDecNum(2);
        frame.b = GetChannelDecNum(3);
        frame.a = GetChannelDecNum(4);
        frame.inputMode = eRGBAChannelInputModeInteger;
        return frame;
    }
    
private:
    void _Set(HexStr hex) {
        HelperUtils::AutoFillHexStr(hex, _hexFrame.channelMode, "0");
        _hexFrame.hex = hex;
    }
};


#endif /* Chromatic4Cpp_HEX_hpp */
