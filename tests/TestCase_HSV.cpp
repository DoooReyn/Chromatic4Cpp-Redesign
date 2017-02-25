//
//  TestCase_HSV.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_HSV.hpp"
#include "Chromatic4Cpp.hpp"

void TestCase1_HSV_Constructor() {
    PrintLine("\n");
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a HSV data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    HSV().Dump(); // HSV:000,0.000,0.000
    PrintLine("\t2. with h,s,l bit value");
    HSV(240, 0.2, 0.5).Dump(); // HSV:240,0.200,0.500
    PrintLine("\t3. Random");
    HSV().Random().Dump(); // HSV:207,0.396,0.210
}

void TestCase2_HSV_Frame() {
    PrintLine("\n");
    PrintLine("================== 1-2 Get/Set HSV Data ==================");
    PrintLine("\t1. Set");
    HSV case0 = HSV().Set(120, 0.2, 0.3).Dump(); // HSV:120,0.200,0.300
    PrintLine("\t1. Set by vector value.");
    case0.Hue(90).Saturation(0.8).Value(0.7).Dump(); // HSV:090,0.800,0.700
    PrintLine("\t1. Get");
    case0.Get().Dump(); // HSV:090,0.800,0.700
    PrintLine("\t1. Get vector value.");
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "H:%03d, S:%.03f, V:%.03f",
            case0.Hue(), case0.Saturation(), case0.Value()
            );
    PrintLine(txt); // H:090, S:0.800, V:0.700
}

void TestCase3_HSV_AsRGB() {
    PrintLine("\n");
    PrintLine("================== 1-3 Convert between RGB and HSV ==================");
    RGB rgb = HSV(300,0.5,0.7).AsRGB().Dump(); // sRGB='179,89,179' InputMode='Integer'
    HSV().FromRGB(rgb).Dump().AsRGB().Dump(); // HSV:300,0.503,0.702 \ sRGB='179,89,179' InputMode='Integer'
    HSL().FromRGB(HSV().Random().Dump().AsRGB().Dump()).Dump();
    // HSV:003,0.907,0.744
    // sRGB='190,26,18' InputMode='Integer'
    // HSL:002,0.827,0.408
}

void TestCase_HSV() {
    PrintLine("\n");
    PrintLine("****************** HSV Class TestCases ****************** ");
    TestCase1_HSV_Constructor();
    TestCase2_HSV_Frame();
    TestCase3_HSV_AsRGB();
}
