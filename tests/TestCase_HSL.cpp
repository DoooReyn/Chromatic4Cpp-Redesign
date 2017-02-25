//
//  TestCase_HSL.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_HSL.hpp"
#include "Chromatic4Cpp.hpp"

void TestCase1_HSL_Constructor() {
    PrintLine("\n");
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a HSL data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    HSL().Dump(); // HSL:000,0.000,0.000
    PrintLine("\t2. with h,s,l bit value");
    HSL(240, 0.2, 0.5).Dump(); // HSL:240,0.200,0.500
    PrintLine("\t3. Random");
    HSL().Random().Dump(); // HSL:196,0.401,0.635
}

void TestCase2_HSL_Frame() {
    PrintLine("\n");
    PrintLine("================== 1-2 Get/Set HSL Data ==================");
    PrintLine("\t1. Set");
    HSL case0 = HSL().Set(120, 0.2, 0.3).Dump(); // HSL:120,0.200,0.300
    PrintLine("\t1. Set by vector value.");
    case0.Hue(90).Saturation(0.8).Lightness(0.7).Dump(); // HSL:090,0.800,0.700
    PrintLine("\t1. Get");
    case0.Get().Dump(); // HSL:090,0.800,0.700
    PrintLine("\t1. Get vector value.");
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "H:%03d, S:%.03f, L:%.03f",
            case0.Hue(), case0.Saturation(), case0.Lightness()
            );
    PrintLine(txt); // H:090, S:0.800, L:0.700
}

void TestCase3_HSL_AsRGB() {
    PrintLine("\n");
    PrintLine("================== 1-3 Convert between RGB and HSL ==================");
    RGB rgb = HSL(300,0.5,0.7).AsRGB().Dump(); // sRGB='217,140,217' InputMode='Integer'
    HSL().FromRGB(rgb).Dump().AsRGB().Dump(); // HSL:300,0.503,0.700 \ sRGB='217,140,217' InputMode='Integer'
    HSL().Random().Dump().AsRGB(); // HSL:356,0.263,0.611 (random)
}

void TestCase_HSL() {
    PrintLine("\n");
    PrintLine("****************** HSL Class TestCases ****************** ");
    TestCase1_HSL_Constructor();
    TestCase2_HSL_Frame();
    TestCase3_HSL_AsRGB();
}
