//
//  Chromatic4Cpp_HSL.hpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_HSL_hpp
#define Chromatic4Cpp_HSL_hpp

#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"

class HSL {
private:
    HSLFrame _frame;
    
public:
    HSL() {
        Set(HSLFrame::HUE_MIN, HSLFrame::HSL_MIN, HSLFrame::HSL_MIN);
    }
    
    HSL(HueBit _h, HSLBit _s, HSLBit _l) {
        Set(_h, _s, _l);
    }

public:
    HueBit Hue()        { return _frame.h; }
    HSLBit Saturation() { return _frame.s; }
    HSLBit Lightness()  { return _frame.l; }
    
    HSL& Hue(HueBit bit)        { _frame.h = HSLFrame::CheckHueBit(bit); return *this; }
    HSL& Saturation(HSLBit bit) { _frame.s = HSLFrame::CheckHSLBit(bit); return *this; }
    HSL& Lightness(HSLBit bit)  { _frame.l = HSLFrame::CheckHSLBit(bit); return *this; }
    
    HSL& Dump() {
        _frame.Dump();
        return *this;
    }
    
    HSL& Set(HueBit _h, HSLBit _s, HSLBit _l) {
        _frame.Set(_h, _s, _l);
        return *this;
    }
    
    HSLFrame Get() {
        return _frame.Clone();
    }
    
    HSL& Random() {
        _frame.Random();
        return *this;
    }
    
    RGB AsRGB() {
        float r = 0.f, g = 0.f, b = 0.f;
        float c = (1 - fabs(2 * _frame.l - 1)) * _frame.s;
        float x = c * (1 - fabs(fmod(_frame.h / 60.f, 2) - 1));
        float m = _frame.l - c / 2.f;
        
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
    
    HSL& FromRGB(RGB rgb) {
        float r = rgb.Red()   * 1.f / RGB_MAX;
        float g = rgb.Green() * 1.f / RGB_MAX;
        float b = rgb.Blue()  * 1.f / RGB_MAX;
        float cmax = max03(r, g, b);
        float cmin = min03(r, g, b);
        float delta = cmax - cmin;
        
        _frame.l = (cmax + cmin) / 2.f;
        
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
        
        if(_frame.l == 0 || cmax == cmin) {
            _frame.s = 0;
        } else if ( 0 < _frame.l && _frame.l <= 0.5f) {
            _frame.s = delta / 2 / _frame.l;
        } else if ( _frame.l > 0.5f ) {
            _frame.s = delta / 2 / (1-_frame.l);
        }
        
        return *this;
    }
};
#endif /* Chromatic4Cpp_HSL_hpp */
