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

void TestCases_sRGB() {
    TestCase1_sRGB_Constructor();
}
