//
//  main.cpp
//  SomethingMustBeWrong
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_HEX.hpp"
#include "TestCase_sRGB.hpp"
#include "TestCase_sRGBA.hpp"
#include "TestCase_CMYK.hpp"
#include "TestCase_HSL.hpp"
#include "TestCase_HSV.hpp"
#include "TestCase_Color.hpp"

int main(int argc, const char * argv[]) {
    TestCases_HEX();
    TestCases_sRGB();
    TestCases_sRGBA();
    TestCase_CMYK();
    TestCase_HSL();
    TestCase_HSV();
    TestCase_Color();
}
