//
//  Chromatic4Cpp_CMYK.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_CMYK_hpp
#define Chromatic4Cpp_CMYK_hpp

#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"

class RGB;

class CMYK {
private:
    CMYKFrame _frame;
public:
    CMYK() {
        Set(CMYKFrame::CMYK_MIN, CMYKFrame::CMYK_MIN, CMYKFrame::CMYK_MIN, CMYKFrame::CMYK_MIN);
    }
    
    CMYK(CMYKBit _c, CMYKBit _m, CMYKBit _y, CMYKBit _k) {
        Set(_c, _m, _y, _k);
    }
    
    CMYK& Dump() {
        _frame.Dump();
        return *this;
    }
    
    CMYK& Set(CMYKBit _c, CMYKBit _m, CMYKBit _y, CMYKBit _k) {
        _frame.Set(_c, _m, _y, _k);
        return *this;
    }
    
    CMYKFrame Get() {
        return _frame.Clone();
    }
    
    CMYKBit Cyan()      { return _frame.c; }
    CMYKBit Magenta()   { return _frame.m; }
    CMYKBit Yellow()    { return _frame.y; }
    CMYKBit Black()     { return _frame.k; }
    
    CMYK& Cyan(CMYKBit bit)    { _frame.c = CMYKFrame::CheckCMYKBit(bit); return *this; }
    CMYK& Magenta(CMYKBit bit) { _frame.m = CMYKFrame::CheckCMYKBit(bit); return *this; }
    CMYK& Yellow(CMYKBit bit)  { _frame.y = CMYKFrame::CheckCMYKBit(bit); return *this; }
    CMYK& Black(CMYKBit bit)   { _frame.k = CMYKFrame::CheckCMYKBit(bit); return *this; }
    
    RGB AsRGB() {
        RGBit r = RGB_MAX * (CMYKFrame::CMYK_MAX - _frame.c) * (CMYKFrame::CMYK_MAX - _frame.k) + .5f;
        RGBit g = RGB_MAX * (CMYKFrame::CMYK_MAX - _frame.m) * (CMYKFrame::CMYK_MAX - _frame.k) + .5f;
        RGBit b = RGB_MAX * (CMYKFrame::CMYK_MAX - _frame.y) * (CMYKFrame::CMYK_MAX - _frame.k) + .5f;
        return RGB(r, g, b);
    }
    
    CMYK& FromRGB (RGB rgb) {
        CMYKBit c0 = RGB_MAX - rgb.Red();
        CMYKBit m0 = RGB_MAX - rgb.Green();
        CMYKBit y0 = RGB_MAX - rgb.Blue();
        CMYKBit k = min03(c0, m0, y0);
        _frame.c = (c0-k) * 1.f / ((RGB_MAX-k) == 0 ? 1 : (RGB_MAX-k));
        _frame.m = (m0-k) * 1.f / ((RGB_MAX-k) == 0 ? 1 : (RGB_MAX-k));
        _frame.y = (y0-k) * 1.f / ((RGB_MAX-k) == 0 ? 1 : (RGB_MAX-k));
        _frame.k = k * 1.f / RGB_MAX;
        return *this;
    }
    
    CMYK& Random() {
        setrandomseed();
        _frame.c = random01();
        _frame.m = random01();
        _frame.y = random01();
        _frame.k = random01();
        return *this;
    }
};

#endif /* Chromatic4Cpp_CMYK_hpp */
