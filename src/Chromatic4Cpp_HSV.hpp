//
//  Chromatic4Cpp_HSV.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_HSV_hpp
#define Chromatic4Cpp_HSV_hpp


#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"

class HSV {
private:
    HSVFrame _frame;
    
public:
    HSV() {
        Set(HSVFrame::HUE_MIN, HSVFrame::HSV_MIN, HSVFrame::HSV_MIN);
    }
    
    HSV(HueBit _h, HSVBit _s, HSVBit _v) {
        Set(_h, _s, _v);
    }
    
public:
    HueBit Hue()        { return _frame.h; }
    HSVBit Saturation() { return _frame.s; }
    HSVBit Value()      { return _frame.v; }
    
    HSV& Hue(HueBit bit)        { _frame.h = HSVFrame::CheckHueBit(bit); return *this; }
    HSV& Saturation(HSVBit bit) { _frame.s = HSVFrame::CheckHSVBit(bit); return *this; }
    HSV& Value(HSVBit bit)      { _frame.v = HSVFrame::CheckHSVBit(bit); return *this; }
    
    HSV& Dump() {
        _frame.Dump();
        return *this;
    }
    
    HSV& Set(HueBit _h, HSVBit _s, HSVBit _v) {
        _frame.Set(_h, _s, _v);
        return *this;
    }
    
    HSVFrame Get() {
        return _frame.Clone();
    }
    
    HSV& Random() {
        _frame.Random();
        return *this;
    }
    
    RGB AsRGB() {
        float r = .0f, g = .0f, b = .0f;
        float c = _frame.v * _frame.s;
        float x = c * (1 - fabs(fmod(_frame.h / 60.f, 2) - 1));
        float m = _frame.v - c;
        
        if(_frame.h < 60) {
            r = c; g = x; b = 0;
        } else if (_frame.h < 120) {
            r = x; g = c; b = 0;
        } else if (_frame.h < 180) {
            r = 0; g = c; b = x;
        } else if (_frame.h < 240) {
            r = 0; g = x; b = c;
        } else if (_frame.h < 300) {
            r = x; g = 0; b = c;
        } else if (_frame.h < 360) {
            r = c; g = 0; b = x;
        }
        
        r = (r + m) * RGB_MAX + .5f;
        g = (g + m) * RGB_MAX + .5f;
        b = (b + m) * RGB_MAX + .5f;
        
        return RGB(r, g, b);
    }
    
    HSV& FromRGB(RGB rgb) {
        float r = rgb.Red() * 1.f / RGB_MAX;
        float g = rgb.Green() * 1.f / RGB_MAX;
        float b = rgb.Blue() * 1.f / RGB_MAX;
        float cmax = max03(r, g, b);
        float cmin = min03(r, g, b);
        float delta = cmax - cmin;
        
        _frame.v = cmax;
        
        if(cmax == cmin) {
            _frame.h = 0;
        } else if (cmax == r && g >= b) {
            _frame.h = 60 * ((g - b) / delta + 0);
        } else if (cmax == r && g < b) {
            _frame.h = 60 * ((g - b) / delta + 6);
        } else if (cmax == g) {
            _frame.h = 60 * ((b - r) / delta + 2);
        } else if (cmax == b) {
            _frame.h = 60 * ((r - g) / delta + 4);
        }
        
        if(cmax == 0) {
            _frame.s = 0;
        } else {
            _frame.s = 1 - cmin / cmax;
        }
        
        return *this;
    }
};

#endif /* Chromatic4Cpp_HSV_hpp */
