//
//  Chromatic4Cpp_DataFrame.hpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_DataFrame_hpp
#define Chromatic4Cpp_DataFrame_hpp

#import "Chromatic4Cpp_HexColor.hpp"
#import "Chromatic4Cpp_BaseTypes.hpp"
#import "Chromatic4Cpp_HelperUtils.hpp"

/* Some data structions definition, like Hex, RGB, RGBA, and so on. */
    
struct HexFrame {
    HexStr hex;
    ChannelNumMode channelMode;
    HexCheckMode checkMode;
    
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
    RGBit r, g, b;
    RGBAChannelInputMode inputMode;
public:
    sRGBFrame() {
        r = 0;
        g = 0;
        b = 0;
        inputMode = eRGBAChannelInputModeInteger;
    }
    
    sRGBFrame(RGBit _r, RGBit _g, RGBit _b) {
        r = _r;
        g = _g;
        b = _b;
        inputMode = eRGBAChannelInputModeInteger;
    }
    
    int Red()   { return r; }
    int Green() { return g; }
    int Blue()  { return b; }
    
    sRGBFrame& Red(RGBit _r)   { r = _r; return *this; }
    sRGBFrame& Green(RGBit _g) { g = _g; return *this; }
    sRGBFrame& Blue(RGBit _b)  { b = _b; return *this; }
    
    sRGBFrame Clone() { return sRGBFrame(r,g,b); }
    
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
    sRGBAFrame() {
        sRGBFrame();
        a = 255;
    }
    sRGBAFrame(RGBit _r, RGBit _g, RGBit _b) {
        sRGBFrame(_r, _g, _b);
        a = 255;
    }
    sRGBAFrame(RGBit _r, RGBit _g, RGBit _b, RGBit _a) {
        sRGBFrame(_r, _g, _b);
        a = _a;
    }
    int Red()   { return r; }
    int Green() { return g; }
    int Blue()  { return b; }
    int Alpha() { return a; }
    sRGBAFrame& Red(RGBit _r)   { r = _r; return *this; }
    sRGBAFrame& Green(RGBit _g) { g = _g; return *this; }
    sRGBAFrame& Blue(RGBit _b)  { b = _b; return *this; }
    sRGBAFrame& Alpha(RGBit _a) { a = _a; return *this; }
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
    sRGBFrame& DumpAsFloat() {
        char txt[96];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "sRGBA='%.03f,%.3f,%.03f,%.03f' InputMode='%s'",
                r/255.f,g/255.f,b/255.f,a/255.f,
                HelperUtils::GetChannelInputModeName(inputMode)
                );
        PrintLine(txt);
        return *this;
    }
    sRGBFrame& DumpAlphaFloat() {
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
