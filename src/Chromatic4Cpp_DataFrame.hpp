//
//  Chromatic4Cpp_DataFrame.hpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_DataFrame_hpp
#define Chromatic4Cpp_DataFrame_hpp

#include "Chromatic4Cpp_HexColor.hpp"
#include "Chromatic4Cpp_BaseTypes.hpp"
#include "Chromatic4Cpp_HelperUtils.hpp"

/* Some data structions definition, like Hex, RGB, RGBA, and so on. */
    
struct HexFrame {
public:
    HexStr hex;
    ChannelNumMode channelMode;
    HexCheckMode checkMode;

public:
    HexFrame() {
        hex = HexColor::BLACK;
        channelMode = eChannelNumMode3;
        checkMode = eHexCheckModeAutoConvert;
    }
    
    HexFrame(HexStr _hex, ChannelNumMode _channelMode, HexCheckMode _checkMode ) {
        hex = _hex;
        channelMode = _channelMode;
        checkMode = _checkMode;
    }
    
    HexFrame Clone() {
        return HexFrame(hex, channelMode, checkMode);
    }
    
    HexFrame& Dump() {
        char txt[80];
        memset(txt, 0, sizeof(txt));
        string sub = hex.substr(0, hex.size());
        HelperUtils::UpperCaseStr(sub);
        sprintf(txt, "Hex='#%s' CheckMode='%s' ChannelMode='%s'",
                sub.c_str(),// Uppercase as default
                HelperUtils::GetCheckModeName(checkMode),
                HelperUtils::GetChannelModeName(channelMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    HexFrame& Random() {
        hex.clear();
        setrandomseed();
        hex.append(HelperUtils::Number2Hex(randomAB(RGB_MIN, RGB_MAX)));
        hex.append(HelperUtils::Number2Hex(randomAB(RGB_MIN, RGB_MAX)));
        hex.append(HelperUtils::Number2Hex(randomAB(RGB_MIN, RGB_MAX)));
        HelperUtils::AutoFillHexStr(hex, eChannelNumMode3, "0");
        return *this;
    }
};

struct sRGBFrame {
public:
    RGBit r, g, b;
    RGBAChannelInputMode inputMode;
    
public:
    sRGBFrame(RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = RGB_MIN;
        g = RGB_MIN;
        b = RGB_MIN;
        inputMode = mode;
    }
    
    sRGBFrame(RGBit _r, RGBit _g, RGBit _b, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = _r;
        g = _g;
        b = _b;
        inputMode = mode;
    }
    
public:
    int Red()   { return r; }
    
    int Green() { return g; }
    
    int Blue()  { return b; }
    
    sRGBFrame& Red(RGBit _r)   { r = _r; return *this; }
    
    sRGBFrame& Green(RGBit _g) { g = _g; return *this; }
    
    sRGBFrame& Blue(RGBit _b)  { b = _b; return *this; }
    
    sRGBFrame Clone() { return sRGBFrame(r,g,b,inputMode); }
    
    sRGBFrame& Dump() {
        char txt[64];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGB='%d,%d,%d' InputMode='%s'",
                r, g, b,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBFrame& DumpAsFloat() {
        char txt[96];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGB='%.03f,%.3f,%.03f' InputMode='%s'",
                r*1.f/RGB_MAX, g*1.f/RGB_MAX, b*1.f/RGB_MAX,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBFrame& Random() {
        setrandomseed();
        r = randomAB(RGB_MIN, RGB_MAX);
        g = randomAB(RGB_MIN, RGB_MAX);
        b = randomAB(RGB_MIN, RGB_MAX);
        return *this;
    }
    
    void CheckInputMode(RGBAChannelInputMode mode) {
        if(inputMode == eRGBAChannelInputModeAlphaFloat) {
            PrintLine("!!!warning: 'AlphaFloat Mode' is not compatible for RGB, so it will not work.");
            inputMode = eRGBAChannelInputModeInteger;
        } else {
            inputMode = mode;
        }
    }
};

struct sRGBAFrame : public sRGBFrame {
public:
    RGBit a;
    
public:
    sRGBAFrame(RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = RGB_MIN;
        g = RGB_MIN;
        b = RGB_MIN;
        a = RGB_MAX;
        inputMode = mode;
    }
    
    sRGBAFrame(RGBit _r, RGBit _g, RGBit _b, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = _r;
        g = _g;
        b = _b;
        a = RGB_MAX;
        inputMode = mode;
    }
    
    sRGBAFrame(RGBit _r, RGBit _g, RGBit _b, RGBit _a, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
        inputMode = mode;
    }
    
    int Red()   { return r; }
    
    int Green() { return g; }
    
    int Blue()  { return b; }
    
    int Alpha() { return a; }
    
    sRGBAFrame& Red(RGBit _r)   { r = _r; return *this; }
    
    sRGBAFrame& Green(RGBit _g) { g = _g; return *this; }
    
    sRGBAFrame& Blue(RGBit _b)  { b = _b; return *this; }
    
    sRGBAFrame& Alpha(RGBit _a) { a = _a; return *this; }
    
    sRGBAFrame Clone() { return sRGBAFrame(r,g,b,a,inputMode); }
    
    sRGBAFrame& Dump() {
        char txt[64];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGBA='%d,%d,%d,%d' InputMode='%s'",
                r,g,b,a,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBAFrame& DumpAsFloat() {
        char txt[96];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGBA='%.03f,%.3f,%.03f,%.03f' InputMode='%s'",
                r*1.f/RGB_MAX, g*1.f/RGB_MAX, b*1.f/RGB_MAX, a*1.f/RGB_MAX,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBAFrame& DumpAlphaFloat() {
        char txt[64];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGBA='%d,%d,%d,%.03f' InputMode='%s'",
                r, g, b, a*1.f/RGB_MAX,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBAFrame& Random() {
        setrandomseed();
        r = randomAB(RGB_MIN, RGB_MAX);
        g = randomAB(RGB_MIN, RGB_MAX);
        b = randomAB(RGB_MIN, RGB_MAX);
        a = randomAB(RGB_MIN, RGB_MAX);
        return *this;
    }
};


struct CMYKFrame {
public:
    CMYKBit c, m, y, k;
    constexpr static const CMYKBit CMYK_MIN = 0.000f;
    constexpr static const CMYKBit CMYK_MAX = 1.000f;
    
public:
    CMYKFrame() {
        c = CMYK_MIN, m = CMYK_MIN, y = CMYK_MIN, k = CMYK_MIN;
    }
    CMYKFrame(CMYKBit _c, CMYKBit _m, CMYKBit _y, CMYKBit _k) {
        Set(_c, _m, _y, _k);
    }
    
public:
    CMYKBit Cyan()      { return c; }
    CMYKBit Magenta()   { return m; }
    CMYKBit Yellow()    { return y; }
    CMYKBit Black()     { return k; }
    
    CMYKFrame& Cyan(CMYKBit bit)    { c = CheckCMYKBit(bit); return *this; }
    CMYKFrame& Magenta(CMYKBit bit) { m = CheckCMYKBit(bit); return *this; }
    CMYKFrame& Yellow(CMYKBit bit)  { y = CheckCMYKBit(bit); return *this; }
    CMYKFrame& Black(CMYKBit bit)   { k = CheckCMYKBit(bit); return *this; }
    
    CMYKFrame& Set(CMYKBit _c, CMYKBit _m, CMYKBit _y, CMYKBit _k) {
        c = CheckCMYKBit(_c), m = CheckCMYKBit(_m), y = CheckCMYKBit(_y), k = CheckCMYKBit(_k);
        return *this;
    }
    
    CMYKFrame& Dump() {
        char txt[32];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "CMYK:%.03f,%.03f,%.03f,%.03f", c, m, y, k);
        PrintLine(txt);
        return *this;
    }
    
    CMYKFrame Clone() {
        return CMYKFrame(c, m, y, k);
    }
    
    CMYKFrame& Random() {
        setrandomseed();
        c = random01();
        m = random01();
        y = random01();
        k = random01();
        return *this;
    }

    static CMYKBit CheckCMYKBit(CMYKBit bit) {
        if(bit < CMYK_MIN) return CMYK_MIN;
        if(bit > CMYK_MAX) return CMYK_MAX;
        return bit;
    }
};


struct HSLFrame {
public:
    HueBit h;
    HSLBit s, l;
    const static HueBit HUE_MIN = 0;
    const static HueBit HUE_MAX = 359;
    static constexpr HSLBit HSL_MIN = 0.000f;
    static constexpr HSLBit HSL_MAX = 1.000f;
    
public:
    HSLFrame() {
        h = HUE_MIN;
        s = l = HSL_MIN;
    }
    
    HSLFrame(HueBit _h, HSLBit _s, HSLBit _l) {
        Set(_h, _s, _l);
    }
    
public:
    HueBit Hue()        { return h; }
    HSLBit Saturation() { return s; }
    HSLBit Lightness()  { return l; }
    
    HSLFrame& Hue(HueBit bit)        { h = CheckHueBit(bit); return *this; }
    HSLFrame& Saturation(HSLBit bit) { s = CheckHSLBit(bit); return *this; }
    HSLFrame& Lightness(HSLBit bit)  { l = CheckHSLBit(bit); return *this; }
    
    HSLFrame& Set(HueBit _h, HSLBit _s, HSLBit _l) {
        h = CheckHueBit(_h);
        s = CheckHSLBit(_s);
        l = CheckHSLBit(_l);
        return *this;
    }
    
    HSLFrame& Dump() {
        char txt[32];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "HSL:%03d,%.03f,%.03f", h, s, l);
        PrintLine(txt);
        return *this;
    }
    
    HSLFrame Clone() {
        return HSLFrame(h, s, l);
    }
    
    HSLFrame& Random() {
        setrandomseed();
        h = randomAB(HUE_MIN, HUE_MAX);
        s = random01();
        l = random01();
        return *this;
    }
    
    static HueBit CheckHueBit(HueBit bit) {
        if(bit < HUE_MIN) return HUE_MIN;
        if(bit > HUE_MAX) return HUE_MAX;
        return bit;
    }
    
    static HSLBit CheckHSLBit(HSLBit bit) {
        if(bit < HSL_MIN) return HSL_MIN;
        if(bit > HSL_MAX) return HSL_MAX;
        return bit;
    }
};


struct HSVFrame {
public:
    HueBit h;
    HSVBit s, v;
    const static HueBit HUE_MIN = 0;
    const static HueBit HUE_MAX = 359;
    static constexpr HSVBit HSV_MIN = 0.000f;
    static constexpr HSVBit HSV_MAX = 1.000f;
    
public:
    HSVFrame() {
        h = HUE_MIN;
        s = v = HSV_MIN;
    }
    
    HSVFrame(HueBit _h, HSVBit _s, HSVBit _l) {
        Set(_h, _s, _l);
    }
    
public:
    HueBit Hue()        { return h; }
    HSVBit Saturation() { return s; }
    HSVBit Value()      { return v; }
    
    HSVFrame& Hue(HueBit bit)        { h = CheckHueBit(bit); return *this; }
    HSVFrame& Saturation(HSVBit bit) { s = CheckHSVBit(bit); return *this; }
    HSVFrame& Value(HSVBit bit)      { v = CheckHSVBit(bit); return *this; }
    
    HSVFrame& Set(HueBit _h, HSVBit _s, HSVBit _v) {
        h = CheckHueBit(_h);
        s = CheckHSVBit(_s);
        v = CheckHSVBit(_v);
        return *this;
    }
    
    HSVFrame& Dump() {
        char txt[32];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "HSV:%03d,%.03f,%.03f", h, s, v);
        PrintLine(txt);
        return *this;
    }
    
    HSVFrame Clone() {
        return HSVFrame(h, s, v);
    }
    
    HSVFrame& Random() {
        setrandomseed();
        h = randomAB(HUE_MIN, HUE_MAX);
        s = random01();
        v = random01();
        return *this;
    }
    
    static HueBit CheckHueBit(HueBit bit) {
        if(bit < HUE_MIN) return HUE_MIN;
        if(bit > HUE_MAX) return HUE_MAX;
        return bit;
    }
    
    static HSLBit CheckHSVBit(HSVBit bit) {
        if(bit < HSV_MIN) return HSV_MIN;
        if(bit > HSV_MAX) return HSV_MAX;
        return bit;
    }
};
#endif /* Chromatic4Cpp_DataFrame_hpp */
