//
//  Chromatic4Cpp_HelperUtils.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/22.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatic4Cpp.hpp"

using namespace Chromatic4Cpp;
using namespace HelperUtils;
using namespace ColorSpace;
using namespace DataFrame;
using namespace HexColor;
using namespace std;

/****************************************************************************************************************************************
 * HellperUtils Implementation
 ****************************************************************************************************************************************/

const char* HelperUtils::GetChannelModeName(ChannelMode mode) {
    if(mode == eChannel3)
        return "3-Channel";
    else
        return "4-Channel";
}

const char* HelperUtils::GetCheckModeName(CheckMode mode) {
    if(mode == eAutoConvert)
        return "AutoConvert";
    else if(mode == eSkipInvalid)
        return "SkipInvalid";
    else
        return "Strict";
}

HexStr HelperUtils::AutoConvertHexStr(const HexStr& hex) {
    HexStr ret;
    ret.clear();
    for(int i = 0; i < hex.size(); i++) {
        bool check = CheckHexChar(hex.at(i));
        if(check)
            ret += hex.at(i);
        else
            ret += "0";
    }
    return ret;
}

HexStr HelperUtils::SkipInvalidHexStr(const HexStr& hex) {
    HexStr ret;
    ret.clear();
    for(int i = 0; i < hex.size(); i++) {
        if(!CheckHexChar(hex.at(i))) continue;
        ret += hex.at(i);
    }
    return ret;
}

bool HelperUtils::StrictCheckHexStr(const HexStr& hex) {
    for(int i = 0; i < hex.size(); i++) {
        if(!CheckHexChar(hex.at(i)))
        {
            HexStr s = HexStr("Warning!!! Invalid hex string : '") + hex + "'";
            PrintLine(s.c_str());
            return false;
        }
    }
    return true;
}

unsigned char HelperUtils::GetChannelModeSize(DataFrame::ChannelMode mode) {
    return mode == eChannel3 ? 6 : 8;
}

void HelperUtils::AutoFillHexStr(HexStr& hex, DataFrame::ChannelMode mode, const HexStr& c) {
    int modesize = GetChannelModeSize(mode);
    long fillsize = hex.size() - modesize;
    if(fillsize >= 0) {
        hex = hex.substr(0, modesize);
    } else {
        for(int i=0; i<-fillsize; i++)
            hex += c;
    }
}

bool HelperUtils::CheckHexChar(HexBit hex) {
    if(hex >= '0' && hex <= '9') return true;
    if(hex >= 'A' && hex <= 'F') return true;
    if(hex >= 'a' && hex <= 'f') return true;
    return false;
}

HexBit HelperUtils::UpperCaseChar(HexBit hex) {
    return (hex >= 'a' && hex <= 'z') ? hex-'a'+'A' : hex;
}

HexBit HelperUtils::LowerCaseChar(HexBit hex) {
    return (hex >= 'A' && hex <= 'Z') ? hex-'A'+'a' : hex;
}

void HelperUtils::UpperCaseStr(HexStr& hex) {
    for (unsigned long i=0; i<hex.size(); i++) {
        hex.at(i) = UpperCaseChar(hex.at(i));
    }
}
void HelperUtils::LowerCaseStr(HexStr& hex) {
    for (unsigned long i=0; i<hex.size(); i++) {
        hex.at(i) = LowerCaseChar(hex.at(i));
    }
}

unsigned long HelperUtils::Hex2Number(const HexStr& hex) {
    if(!StrictCheckHexStr(hex)) return 0;
    int num = 0;
    sscanf(hex.c_str(), "%x", &num);
    return num;
}
