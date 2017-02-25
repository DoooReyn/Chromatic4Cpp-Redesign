
//  TestCase_sRGB.cpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/23.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//
#include "Chromatic4Cpp.hpp"
#include "TestCase_sRGB.hpp"

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
    sRGBFrame frame = sRGBFrame(77,88,99);
    RGB(frame).Dump(); // sRGB='77,88,99' InputMode='Integer'
    PrintLine("\t6. RGBAChannelInputMode is one argument, but its value is eRGBAChannelInputModeInteger as default");
    RGB(SANDYBROWN, eRGBAChannelInputModeInteger).Dump(); // sRGB='244,164,96' InputMode='Integer'
    PrintLine("\t7. Random");
    RGB().Random().Dump(); // sRGB='162,202,41' InputMode='Integer'
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
    PrintLine("\n");
    PrintLine("================== 1-3 RGB Getter/Setter ==================");
    PrintLine("\t1. Set RGB data :");
    RGB case0 = RGB().Set(120,120,120).Dump(); // sRGB='120,120,120' InputMode='Integer'
    PrintLine("\t2. Get sRGBFrame data :");
    case0.Get().Dump(); // sRGB='120,120,120' InputMode='Integer'
    PrintLine("\t3. Set sRGBFrame data with R,G,B vector:");
    case0.Red(97).Green(98).Blue(99).Dump(); // sRGB='97,98,99' InputMode='Integer'
    PrintLine("\t4. Get R,G,B vector:");
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "R:%03d G:%03d B:%03d", case0.Red(), case0.Green(), case0.Blue());
    PrintLine(txt); // R:097 G:098 B:099
}


void TestCase4_sRGB_AsHEX() {
    PrintLine("\n");
    PrintLine("================== 1-4 RGB As HexStr && HEX ==================");
    PrintLine("\t1. RGB(PLUM)'s rgb data :");
    RGB rgb = RGB(PLUM).Dump(); // sRGB='221,160,221' InputMode='Integer'
    PrintLine("\t2. RGB(PLUM)'s hex string :");
    const HexStr hexStr = rgb.HexString();
    PrintLine(hexStr); // sRGB='221,160,221' InputMode='Integer'
    PrintLine("\t3. RGB(PLUM) as HEX class :");
    rgb.Dump().AsHEX().Dump(); // Hex='#DDA0DD' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t4. Use HexStr to generate a HEX class :");
    HEX(hexStr).Dump(); // Hex='#DDA0DD' CheckMode='AutoConvert' ChannelMode='3-Channel'
}

void TestCases_sRGB() {
    PrintLine("\n");
    PrintLine("****************** RGB Class TestCases ****************** ");
    TestCase1_sRGB_Constructor();
    TestCase2_sRGB_InputMode();
    TestCase3_sRGB_sFrame();
    TestCase4_sRGB_AsHEX();
}
