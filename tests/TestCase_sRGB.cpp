//
//  TestCase_sRGB.cpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/23.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//
#include "Chromatic4Cpp.hpp"
#include "TestCase_sRGB.hpp"
#include <iostream>
using namespace Chromatic4Cpp;
using namespace HexColor;
using namespace ColorSpace;
using namespace HelperUtils;
using namespace std;

void TestCase1_sRGB_Constructor() {
    PrintLine("\n");
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a RGB data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    RGB().Dump(); // sRGB='0,0,0' InputMode='Integer'
    PrintLine("\t2. with r,g,b bit value");
    RGB(12, 12, 12).Dump(); // sRGB='12,12,12' InputMode='Integer'
    PrintLine("\t3. with hex string");
    RGB("9823918").Dump(); // sRGB='152,35,145' InputMode='Integer'
    PrintLine("\t4. with HEX class");
    RGB(HEX("F19oo20488", eHexCheckModeSkipInvalid)).Dump(); // sRGB='241,146,4' InputMode='Integer'
    PrintLine("\t5. with sRGBFrame data");
    RGB(sRGBFrame(77,88,99)).Dump(); // sRGB='77,88,99' InputMode='Integer'
    PrintLine("\t6. RGBAChannelInputMode is one argument, but its value is eRGBAChannelInputModeInteger as default");
    RGB(SANDYBROWN, eRGBAChannelInputModeInteger).Dump(); // sRGB='244,164,96' InputMode='Integer'
}

void TestCase2_sRGB_InputMode() {
    PrintLine("\n");
    PrintLine("================== 1-2 Channel Input Mode ==================");
    PrintLine("This mode controls the output of RGB class.");
    PrintLine("There are 3 modes: Integer, Float, AlphaFloat(Used by RGBA)");
    PrintLine("\t1. Integer mode");
    RGB(KHAKI, eRGBAChannelInputModeInteger).Dump(); // sRGB='240,230,140' InputMode='Integer'
    PrintLine("\t2. Float Mode");
    RGB(KHAKI, eRGBAChannelInputModeFloat).Dump(); // sRGB='0.941,0.902,0.549' InputMode='Float'
    PrintLine("\t3. AlphaFloat Mode, will be considered as Integer Mode.");
    RGB(KHAKI, eRGBAChannelInputModeAlphaFloat).Dump(); // sRGB='240,230,140' InputMode='Integer'
}

void TestCase3_sRGB_sFrame() {
    // sRGB='221,160,221' InputMode='Integer'
    // Hex='#DDA0DD' CheckMode='AutoConvert' ChannelMode='3-Channel'
}


void TestCase4_sRGB_AsHEX() {
    PrintLine("\n");
    PrintLine("================== 1-4 RGB As Hex ==================");
    PrintLine("RGB(PLUM)'s rgb data :");
    RGB rgb = RGB(PLUM).Dump(); // sRGB='221,160,221' InputMode='Integer'
    PrintLine("RGB(PLUM)'s hex string :");
    const HexStr hexStr = rgb.GetHexStr();
    PrintLine(hexStr); // sRGB='221,160,221' InputMode='Integer'
    PrintLine("RGB(PLUM) as HEX class :");
    rgb.Dump().AsHEX().Dump(); // Hex='#DDA0DD' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("Use HexStr to generate a HEX class :");
    HEX(hexStr).Dump(); // Hex='#DDA0DD' CheckMode='AutoConvert' ChannelMode='3-Channel'
}

void TestCases_sRGB() {
    TestCase1_sRGB_Constructor();
    TestCase2_sRGB_InputMode();
    TestCase3_sRGB_sFrame();
    TestCase4_sRGB_AsHEX();
}
