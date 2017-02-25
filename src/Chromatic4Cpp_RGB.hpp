//
//  Chromatic4Cpp_RGB.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_RGB_hpp
#define Chromatic4Cpp_RGB_hpp

#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"
#include "Chromatic4Cpp_HEX.hpp"

class RGB {
private:
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
        HelperUtils::AutoFillHexStr(ret, eChannelNumMode3, "0");
        return ret;
    }
    
private:
    void _Set(sRGBFrame& frame) {
        frame.CheckInputMode(frame.inputMode);
        _frame.Red(frame.Red());
        _frame.Green(frame.Green());
        _frame.Blue(frame.Blue());
        _frame.inputMode = frame.inputMode;
    }
};


#endif /* Chromatic4Cpp_RGB_hpp */
