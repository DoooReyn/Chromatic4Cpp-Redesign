//
//  Chromatic4Cpp_HelperUtils.hpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_HelperUtils_hpp
#define Chromatic4Cpp_HelperUtils_hpp

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Chromatic4Cpp_BaseTypes.hpp"
using namespace std;

/* Some functions to make Chromatic4Cpp useful and workable. */

template<class T> void PrintLine(T t) {
    cout << t << endl;
}

#define MIN(a,b) (a > b ? b : a)
#define MAX(a,b) (a > b ? a : b)
#define max03(f1, f2, f3) MAX(MAX(f1, f2), f3)
#define min03(f1, f2, f3) MIN(MIN(f1, f2), f3)
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
#define setrandomseed()     srand((unsigned)time(NULL)+rand())
#define randomAB(a,b)       (rand() % (b-a+1))+ a
#define random01()          rand() / double(RAND_MAX)


class HelperUtils {
public:
    static bool CheckHexChar(HexBit hex) {
        if(hex >= '0' && hex <= '9') return true;
        if(hex >= 'A' && hex <= 'F') return true;
        if(hex >= 'a' && hex <= 'f') return true;
        return false;
    }
    
    static HexStr AutoConvertHexStr(const HexStr& hex) {
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
    
    static HexStr SkipInvalidHexStr(const HexStr& hex) {
        HexStr ret;
        ret.clear();
        for(int i = 0; i < hex.size(); i++) {
            if(!CheckHexChar(hex.at(i))) continue;
            ret += hex.at(i);
        }
        return ret;
    }
    
    static bool StrictCheckHexStr(const HexStr& hex) {
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
    
    static unsigned char GetChannelModeSize(ChannelNumMode mode) {
        return mode == eChannelNumMode3 ? 6 : 8;
    }
    
    
    static void AutoFillHexStr(HexStr& hex, ChannelNumMode mode, const HexStr& c) {
        int modesize = GetChannelModeSize(mode);
        long fillsize = hex.size() - modesize;
        if(fillsize >= 0) {
            hex = hex.substr(0, modesize);
        } else {
            for(int i=0; i<-fillsize; i++)
                hex += c;
        }
    }
    
    static const char* GetChannelModeName(ChannelNumMode mode) {
        if(mode == eChannelNumMode3)
            return "3-Channel";
        else
            return "4-Channel";
    }
    
    static const char* GetCheckModeName(HexCheckMode mode) {
        if(mode == eHexCheckModeAutoConvert)
            return "AutoConvert";
        else if(mode == eHexCheckModeSkipInvalid)
            return "SkipInvalid";
        else
            return "Strict";
    }
    
    static const char* GetChannelInputModeName(RGBAChannelInputMode mode) {
        if(mode == eRGBAChannelInputModeInteger)
            return "Integer";
        else if(mode == eRGBAChannelInputModeFloat)
            return "Float";
        else
            return "AlphaFloat";
    }
    
    static HexBit UpperCaseChar(HexBit hex) {
        return (hex >= 'a' && hex <= 'z') ? hex-'a'+'A' : hex;
    }
    
    static HexBit LowerCaseChar(HexBit hex) {
        return (hex >= 'A' && hex <= 'Z') ? hex-'A'+'a' : hex;
    }
    
    static void UpperCaseStr(HexStr& hex) {
        for (unsigned long i=0; i<hex.size(); i++) {
            hex.at(i) = UpperCaseChar(hex.at(i));
        }
    }
    
    static void LowerCaseStr(HexStr& hex) {
        for (unsigned long i=0; i<hex.size(); i++) {
            hex.at(i) = LowerCaseChar(hex.at(i));
        }
    }
    
    static unsigned long Hex2Number(const HexStr& hex) {
        if(!StrictCheckHexStr(hex)) return 0;
        int num = 0;
        sscanf(hex.c_str(), "%x", &num);
        return num;
    }
    
    static const HexStr Number2Hex(int num) {
        char txt[6];
        memset(txt, 0, sizeof(txt));
        sprintf(txt, "%x", num);
        string ret = txt;
        UpperCaseStr(ret);
        return ret;
    }
};

#endif /* Chromatic4Cpp_HelperUtils_hpp */
