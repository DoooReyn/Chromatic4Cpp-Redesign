//
//  TestCase_sRGBA.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatic4Cpp.hpp"
#include "TestCase_sRGBA.hpp"

void TestCase1_sRGBA_Constructor() {
    PrintLine("\n");
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a RGBA data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    RGBA().Dump(); // sRGBA='0,0,0,255' InputMode='Integer'
    PrintLine("\t2. with r,g,b,a bit value");
    RGBA(12, 12, 12, 12).Dump(); // sRGBA='12,12,12,12' InputMode='Integer'
    PrintLine("\t3. with hex string");
    RGBA("9823918").Dump(); // sRGBA='152,35,145,128' InputMode='Integer'
    PrintLine("\t4. with HEX class");
    RGBA(HEX("F19oo20488", eChannelNumMode4, eHexCheckModeSkipInvalid)).Dump(); // sRGBA='241,146,4,136' InputMode='Integer'
    PrintLine("\t5. with sRGBAFrame data");
    sRGBAFrame frame = sRGBAFrame(77,88,99,111);
    RGBA(frame).Dump(); // sRGBA='77,88,99,111' InputMode='Integer'
}

void TestCase2_sRGBA_InputMode() {
    PrintLine("\n");
    PrintLine("================== 1-2 Channel Input Mode ==================");
    PrintLine("This mode controls the output of RGB class.");
    PrintLine("There are 3 modes: Integer, Float, AlphaFloat(Used by RGBA)");
    PrintLine("\t1. Integer mode");
    RGBA(KHAKI, eRGBAChannelInputModeInteger).Dump(); // sRGBA='240,230,140,0' InputMode='Integer'
    PrintLine("\t2. Float Mode");
    RGBA(KHAKI, eRGBAChannelInputModeFloat).Dump(); // sRGBA='0.941,0.902,0.549,0.000' InputMode='Float'
    PrintLine("\t3. AlphaFloat Mode, will be considered as Integer Mode.");
    RGBA(KHAKI, eRGBAChannelInputModeAlphaFloat).Dump(); // sRGBA='240,230,140,0.000' InputMode='AlphaFloat'
}

void TestCase3_sRGBA_sFrame() {
    PrintLine("\n");
    PrintLine("================== 1-3 RGBA Getter/Setter ==================");
    PrintLine("\t1. Set RGBA data :");
    RGBA case0 = RGBA().Set(120,120,120,120).Dump(); // sRGBA='120,120,120,120' InputMode='Integer'
    PrintLine("\t2. Get sRGBAFrame data :");
    case0.Get().Dump(); // sRGBA='120,120,120,120' InputMode='Integer'
    PrintLine("\t3. Set sRGBAFrame data with R,G,B vector:");
    case0.Red(97).Green(98).Blue(99).Alpha(111).Dump(); // sRGBA='97,98,99,111' InputMode='Integer'
    PrintLine("\t3. Get R,G,B,A vector:");
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "R:%03d G:%03d B:%03d A:%03d", case0.Red(), case0.Green(), case0.Blue(), case0.Alpha());
    PrintLine(txt); // R:097 G:098 B:099 A:111
}


void TestCase4_sRGBA_AsHEX() {
    PrintLine("\n");
    PrintLine("================== 1-4 RGBA As HexStr && HEX ==================");
    PrintLine("\t1. RGB(PLUM)'s rgb data :");
    RGBA case0 = RGBA(PLUM).Dump(); // sRGB='221,160,221,0' InputMode='Integer'
    PrintLine("\t2. RGB(PLUM)'s hex string :");
    const HexStr hexStr = case0.HexString();
    PrintLine(hexStr); // DDA0DD00
    PrintLine("\t3. RGB(PLUM) as HEX class :");
    case0.Dump().AsHEX().Dump(); // Hex='#DDA0DD00' CheckMode='AutoConvert' ChannelMode='4-Channel'
    PrintLine("\t4. Use HexStr to generate a HEX class :");
    HEX(hexStr, eChannelNumMode4).Dump(); // Hex='#DDA0DD00' CheckMode='AutoConvert' ChannelMode='4-Channel'
}

void TestCases_sRGBA() {
    PrintLine("\n");
    PrintLine("****************** RGBA Class TestCases ****************** ");
    TestCase1_sRGBA_Constructor();
    TestCase2_sRGBA_InputMode();
    TestCase3_sRGBA_sFrame();
    TestCase4_sRGBA_AsHEX();
}
