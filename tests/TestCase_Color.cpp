//
//  TestCase_Color.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_Color.hpp"
#include "Chromatic4Cpp.hpp"

void TestCase_AsRGB() {
    PrintLine("\n");
    PrintLine("================== 1-1 Color As RGB ==================");
    PrintLine("\t1. HEX As RGB");
    Color::AsRGB(HEX().Random().Dump()).Dump();
    //    Hex='#A18D9A' CheckMode='AutoConvert' ChannelMode='3-Channel'
    //    sRGB='161,141,154' InputMode='Integer'
    PrintLine("\t1. RGBA As RGB");
    Color::AsRGB(RGBA().Random().Dump()).Dump();
    //    sRGBA='126,113,247,204' InputMode='Integer'
    //    sRGB='126,113,247' InputMode='Integer'
    PrintLine("\t1. CMYK As RGB");
    Color::AsRGB(CMYK().Random().Dump()).Dump();
    //    CMYK:0.413,0.693,0.116,0.697
    //    sRGB='45,24,68' InputMode='Integer'
    PrintLine("\t1. HSL As RGB");
    Color::AsRGB(HSL().Random().Dump()).Dump();
    //    HSL:082,0.652,0.088
    //    sRGB='26,37,8' InputMode='Integer'
    PrintLine("\t1. HSV As RGB");
    Color::AsRGB(HSV().Random().Dump()).Dump();
    //    HSV:281,0.140,0.647
    //    sRGB='158,142,165' InputMode='Integer'
}

void TestCase_Color() {
    TestCase_AsRGB();
}
