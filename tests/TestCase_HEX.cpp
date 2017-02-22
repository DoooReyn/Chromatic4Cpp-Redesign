//
//  TestCase_HEX.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/21.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "TestCase_HEX.hpp"
#include "Chromatic4Cpp.hpp"
#include <iostream>
using namespace Chromatic4Cpp;
using namespace HexColor;
using namespace ColorSpace;
using namespace HelperUtils;
using namespace std;


void TestCase1_HEX_ConvertHex() {
    PrintLine("================== 1-1 Constructor ==================");
    PrintLine("To get a HEX data, u can use constructors as below:");
    PrintLine("\t1. with no arguments as default");
    HEX().Dump(); // Hex='#000000' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t2. with hex string");
    HEX(CYAN).Dump(); // Hex='#00FFFF' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t3. with hex string && channel mode");
    HEX("012345", eChannel3).Dump(); // Hex='#012345' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t4. with hex string && check mode");
    HEX("67890a", eAutoConvert).Dump(); // Hex='#67890A' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t5. with hex string && channel mode && check mode");
    HEX("bcdef0", eChannel3, eAutoConvert).Dump(); // Hex='#BCDEF0' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t6. with hex frame");
    HexFrame hframe = HexFrame("FfCcDd", eChannel3, eAutoConvert);
    HEX(hframe).Dump(); // Hex='#FFCCDD' CheckMode='AutoConvert' ChannelMode='3-Channel'
    
    PrintLine("\n");
    PrintLine("================== 1-2 Channel Mode ==================");
    PrintLine("RGB(A) color has 3 or 4 channels, so here is its meaning.");
    PrintLine("\t1. When it converted to eChannel4, hex string will auto fill/convert to 8 chars.");
    HEX("ff88", eChannel3).Dump(); // Hex='#FF8800' CheckMode='AutoConvert' ChannelMode='3-Channel'
    HEX("ff8080", eChannel4).Dump(); // Hex='#FF808000' CheckMode='AutoConvert' ChannelMode='4-Channel'
    PrintLine("\t2. U can set channel mode by using SetChannelMode() as well.");
    HEX("ff8080").SetChannelMode(eChannel4).Dump(); // Hex='#FF808000' CheckMode='AutoConvert' ChannelMode='4-Channel'
    
    PrintLine("\n");
    PrintLine("================== 1-3 Check Mode ==================");
    PrintLine("I have set 3 modes to convert/check hex string.");
    PrintLine("\t1. In 'eAutoConvert' mode, it will convert invalid hex char to '0'.");
    HEX("ffu881", eAutoConvert).Dump(); // Hex='#FF0881' CheckMode='AutoConvert' ChannelMode='3-Channel'
    PrintLine("\t2. In 'eSkipInvalid' mode, it will skip invalid hex char.");
    HEX("ffu881", eSkipInvalid).Dump(); // Hex='#FF8810' CheckMode='SkipInvalid' ChannelMode='3-Channel'
    PrintLine("\t3. In 'eStrictCheck' mode, it will strict check every hex char, if failed, there will raise a warning tip.");
    HEX("ffu881", eStrictCheck).Dump(); // Warning!!! Invalid hex string : 'ffu881'
                                        // Hex='#000000' CheckMode='Strict' ChannelMode='3-Channel'
    PrintLine("\t4. U can set check mode by using SetCheckMode() as well.");
    HEX("88Af99E(*@ο@*) 哇～").SetChannelMode(eChannel4).SetCheckMode(eSkipInvalid).Dump(); // Hex='#88AF9900' CheckMode='SkipInvalid' ChannelMode='3-Channel'
    
    PrintLine("\n");
    PrintLine("================== 1-4 Get/Set Hex Data ==================");
    PrintLine("\t1. U can get/set hex string whenever u need it.");
    HEX("", eChannel4, eSkipInvalid).Set("88Af99E(*@ο@*) 哇～").Dump(); // Hex='#88AF99E0' CheckMode='SkipInvalid' ChannelMode='4-Channel'
    PrintLine(HEX("FF(12398", eChannel4, eSkipInvalid).Get()); // FF123980
    PrintLine("\t2. U can get/set hex frame data whenever u need it.");
    HEX("FF(1239", eChannel4, eSkipInvalid).GetHexFrame().Dump(); // Hex='#FF123980' CheckMode='SkipInvalid' ChannelMode='4-Channel'
    PrintLine("\t3. However, u cannot modify original hex frame data from GetFrame(), for it returns a copy of original.");
    PrintLine("\t   so, do not try to modify hex frame directly.");
    HEX hex = HEX("FF(12398", eChannel4, eSkipInvalid);
    hframe = hex.GetHexFrame();
    hframe.hex = "888888";
    hframe.Dump(); // Hex='#888888' CheckMode='SkipInvalid' ChannelMode='4-Channel'
    hex.Dump(); // Hex='#FF123980' CheckMode='SkipInvalid' ChannelMode='4-Channel'
    
    PrintLine("\n");
    PrintLine("================== 1-5 Hex && sRGBFrame ==================");
    hex.Convert2sRGBFrame().DumpAlphaFloat(); // sRGB='255,18,57,0.502'
    hex.Convert2sRGBFrame().DumpAsFloat(); // sRGB='1.000,0.071,0.224,0.502'
    hex.SetChannelMode(eChannel3).Convert2sRGBFrame().Alpha(200).Dump(); // sRGB='255,18,57,200'
}
