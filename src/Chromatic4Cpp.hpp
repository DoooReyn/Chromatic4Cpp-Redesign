//
//  Chromatic4Cpp.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/21.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
/*
 * Includes:
 * - BaseTypes
 * - HexColor
 * - HelperUtils
 * - DataFrame
 *      - HexFrame      // completed 90%
 *      - sRGBFrame     // completed 90%
 *      - sRGBAFrame    // completed 80%
 *      - ...           // on plan
 * - ColorSpace
 *      - HEX   // completed 90% ...
 *      - RGB   // completed 90% ...
 *      - RGBA  // on plan
 *      - CMYK  // on plan
 *      - HSL   // on plan
 *      - HSV   // on plan
 *      - HSB   // on plan
 *      - YUV   // on plan
 *      - LAB   // on plan
 *
 * [Reference Link](https://github.com/DoooReyn/Chromatic4cpp)
 ***************************************************************
 */

#ifndef Chromatic4Cpp_hpp
#define Chromatic4Cpp_hpp

#include <iostream>
#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"
#include "Chromatic4Cpp_DataFrame.hpp"
#include "Chromatic4Cpp_HEX.hpp"
#include "Chromatic4Cpp_RGB.hpp"
#include "Chromatic4Cpp_RGBA.hpp"
#include "Chromatic4Cpp_CMYK.hpp"
#include "Chromatic4Cpp_HSL.hpp"
#include "Chromatic4Cpp_HSV.hpp"

using namespace std;
using namespace HexColor;

class Color {
public:
    // As RGB
    static RGB AsRGB(HEX hex) {
        sRGBFrame frame = hex.RGBFrame();
        return RGB().Set(frame);
    }
    
    static RGB AsRGB(RGBA rgba) {
        sRGBAFrame frame = rgba.Get();
        return RGB(frame.r, frame.g, frame.b, frame.inputMode);
    }
    
    static RGB AsRGB(CMYK cmyk) {
        return cmyk.AsRGB();
    }
    
    static RGB AsRGB(HSL hsl) {
        return hsl.AsRGB();
    }
    
    static RGB AsRGB(HSV hsv) {
        return hsv.AsRGB();
    }
};

#endif /* Chromatic4Cpp_hpp */
