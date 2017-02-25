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
};

struct sRGBFrame {
public:
    RGBit r, g, b;
    RGBAChannelInputMode inputMode;
    
public:
    sRGBFrame(RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = 0;
        g = 0;
        b = 0;
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
                r/255.f,g/255.f,b/255.f,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
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
        r = 0;
        g = 0;
        b = 0;
        a = 255;
        inputMode = mode;
    }
    
    sRGBAFrame(RGBit _r, RGBit _g, RGBit _b, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger) {
        r = _r;
        g = _g;
        b = _b;
        a = 255;
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
                r/255.f,g/255.f,b/255.f,a/255.f,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    
    sRGBAFrame& DumpAlphaFloat() {
        char txt[64];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGBA='%d,%d,%d,%.03f' InputMode='%s'",
                r,g,b,a/255.f,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
};



#endif /* Chromatic4Cpp_DataFrame_hpp */
