//
//  TestCase_CMYK.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/26.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_CMYK.hpp"
#include "Chromatic4Cpp.hpp"

void TestCase1_CMYK_Constructor() {
    PrintLine("\n");
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a CMYK data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    CMYK().Dump(); // CMYK:0.000,0.000,0.000,0.000
    PrintLine("\t2. with c,m,y,k bit value");
    CMYK(1.2,4.3,2,0.5).Dump(); // CMYK:1.000,1.000,1.000,0.500
}

void TestCase2_CMYK_Frame() {
    PrintLine("\n");
    PrintLine("================== 1-2 Get/Set CMYK Data ==================");
    PrintLine("\t1. Set");
    CMYK case0 = CMYK().Set(0.1, 0.2, 0.3, 0.4).Dump(); // CMYK:0.100,0.200,0.300,0.400
    PrintLine("\t1. Set by vector value.");
    case0.Cyan(0.9).Magenta(0.8).Yellow(0.7).Black(0.6).Dump(); // CMYK:0.900,0.800,0.700,0.600
    PrintLine("\t1. Get");
    case0.Get().Dump(); // CMYK:0.900,0.800,0.700,0.600
    PrintLine("\t1. Get vector value.");
    char txt[32];
    memset(txt, 0, sizeof(txt));
    sprintf(txt, "C:%.03f, M:%.03f, Y:%.03f, K:%.03f",
            case0.Cyan(), case0.Magenta(), case0.Yellow(), case0.Black()
            );
    PrintLine(txt); // C:0.900, M:0.800, Y:0.700, K:0.600
}

void TestCase3_CMYK_AsRGB() {
    PrintLine("\n");
    PrintLine("================== 1-3 Convert between RGB and CMYK ==================");
    RGB rgb = CMYK(0.4,0.5,0.6,0.7).AsRGB().Dump(); // sRGB='45,38,30' InputMode='Integer'
    CMYK().FromRGB(rgb).Dump().AsRGB().Dump(); // CMYK:0.000,0.174,0.326,0.820 \ sRGB='46,38,31' InputMode='Integer'
}

void TestCase_CMYK() {
    PrintLine("\n");
    PrintLine("****************** CMYK Class TestCases ****************** ");
    TestCase1_CMYK_Constructor();
    TestCase2_CMYK_Frame();
    TestCase3_CMYK_AsRGB();
}
