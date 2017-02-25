
//  Chromatic4Cpp_RGBA.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_RGBA_hpp
#define Chromatic4Cpp_RGBA_hpp

#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"
#include "Chromatic4Cpp_HEX.hpp"
#include "Chromatic4Cpp_RGB.hpp"

class RGBA {
private:
    sRGBAFrame _frame;
    
public:
    RGBA(RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBAFrame frame = sRGBAFrame(0,0,0,255,mode);
        Set(frame);
    }
    
    RGBA(RGBit r, RGBit g, RGBit b, RGBit a, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBAFrame frame = sRGBAFrame(r,g,b,a,mode);
        Set(frame);
    }
    
    RGBA(HexStr hex, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBAFrame frame = HEX(hex, eChannelNumMode4).RGBAFrame();
        frame.inputMode = mode;
        Set(frame);
    }
    
    RGBA(HEX hex, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        sRGBAFrame frame = hex.RGBAFrame();
        frame.inputMode = mode;
        Set(frame);
    }
    
    RGBA(sRGBAFrame& frame) {
        Set(frame);
    }
    
public:
    int Red()   { return _frame.Red(); }
    
    int Green() { return _frame.Green(); }
    
    int Blue()  { return _frame.Blue(); }
    
    int Alpha() { return _frame.Alpha(); }
    
    RGBA& Red(RGBit r)   { _frame.Red(r); return *this; }
    
    RGBA& Green(RGBit g) { _frame.Green(g); return *this; }
    
    RGBA& Blue(RGBit b)  { _frame.Blue(b); return *this; }
    
    RGBA& Alpha(RGBit a)  { _frame.Alpha(a); return *this; }
    
    RGBA& Set(sRGBAFrame& frame) {
        _Set(frame);
        return *this;
    }
    
    RGBA& Set(RGBit r, RGBit g, RGBit b, RGBit a = 255, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        _frame.r = r;
        _frame.g = g;
        _frame.b = b;
        _frame.a = a;
        _frame.inputMode = mode;
        return Set(_frame);
    }
    
    sRGBAFrame Get() { return _frame.Clone(); }
    
    RGBA& Dump() {
        if(_frame.inputMode == eRGBAChannelInputModeFloat)
            _frame.DumpAsFloat();
        else if(_frame.inputMode == eRGBAChannelInputModeInteger)
            _frame.Dump();
        else
            _frame.DumpAlphaFloat();
        return *this;
    }
    
    RGBAChannelInputMode GetChannelInputMode() {
        return _frame.inputMode;
    }
    
    RGBA& SetChannelInputMode(RGBAChannelInputMode mode) {
        return *this;
    }
    
    HEX AsHEX() {
        return HEX(HexString(), eChannelNumMode4);
    }
    
    const HexStr HexString() {
        HexStr ret;
        ret.clear();
        ret.append(HelperUtils::Number2Hex(_frame.Red()));
        ret.append(HelperUtils::Number2Hex(_frame.Green()));
        ret.append(HelperUtils::Number2Hex(_frame.Blue()));
        ret.append(HelperUtils::Number2Hex(_frame.Alpha()));
        HelperUtils::AutoFillHexStr(ret, eChannelNumMode4, "0");
        return ret;
    }
    
private:
    void _Set(sRGBAFrame& frame) {
        _frame.Red(frame.Red());
        _frame.Green(frame.Green());
        _frame.Blue(frame.Blue());
        _frame.Alpha(frame.Alpha());
        _frame.inputMode = frame.inputMode;
    }
};

#endif /* Chromatic4Cpp_RGBA_hpp */
