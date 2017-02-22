//
//  Chromatic4Cpp.hpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/21.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_hpp
#define Chromatic4Cpp_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

/****************************************************************************************************************************************
 * Chromatic4Cpp namespace definition
 * Includes:
 * - BaseTypes
 * - HexColor
 * - HelperUtils
 * - DataFrame
 *      - HexFrame      // completed 90%
 *      - sRGBFrame     // completed 80%
 *      - sRGBAFrame    // completed 80%
 *      - ...           // on plan
 * - ColorSpace
 *      - HEX   // completed 90% ...
 *      - RGB   // refer to [chromatic4cpp](https://github.com/DoooReyn/Chromatic4cpp)
 *      - RGBA  // refer to [chromatic4cpp](https://github.com/DoooReyn/Chromatic4cpp)
 *      - CMYK  // refer to [chromatic4cpp](https://github.com/DoooReyn/Chromatic4cpp)
 *      - HSL   // refer to [chromatic4cpp](https://github.com/DoooReyn/Chromatic4cpp)
 *      - HSV   // refer to [chromatic4cpp](https://github.com/DoooReyn/Chromatic4cpp)
 *      - HSB   // on plan
 *      - YUV   // on plan
 *      - LAB   // on plan
 ****************************************************************************************************************************************/

namespace Chromatic4Cpp {
    
    /* Base data types definition */
    namespace BaseTypes {
        typedef enum {
            eCS_HEX,    //基本完成
            eCS_RGB,    //计划中
            eCS_RGBA,   //计划中
            eCS_CMYK,
            eCS_HSL,
            eCS_HSV,
            eCS_HSB,
            eCS_YUV,
            eCS_LAB,
        } ColorSpaceType;
        
        typedef enum {
            eChannelNumMode3,  // 3 channel (as default, like RGB)
            eChannelNumMode4,  // 4 channel (like RGBA)
        } ChannelNumMode;
        
        typedef enum {
            eHexCheckModeAutoConvert, // auto convert to valid char
            eHexCheckModeSkipInvalid, // skip invalid char
            eHexCheckModeStrictCheck, // would fail
        } HexCheckMode;
        
        typedef enum {
            eRGBAChannelInputModeInteger,
            eRGBAChannelInputModeFloat,
            eRGBAChannelInputModeAlphaFloat,
        } RGBAChannelInputMode;
        
        /* Macro definitions for base data type */
        #define CStr   const char*
        #define HexStr std::string
        #define HexBit unsigned char
        #define RGBit  unsigned char
        #define RGBitf float
    }
    
    
    /* Hex colors definition as below */
    namespace HexColor {
        const HexStr INDIGO                = "4B0082";
        const HexStr GOLD                  = "FFD700";
        const HexStr HOTPINK               = "FF69B4";
        const HexStr FIREBRICK             = "B22222";
        const HexStr INDIANRED             = "CD5C5C";
        const HexStr YELLOW                = "FFFF00";
        const HexStr MISTYROSE             = "FFE4E1";
        const HexStr DARKOLIVEGREEN        = "556B2F";
        const HexStr OLIVE                 = "808000";
        const HexStr DARKSEAGREEN          = "8FBC8F";
        const HexStr PINK                  = "FFC0CB";
        const HexStr TOMATO                = "FF6347";
        const HexStr LIGHTCORAL            = "F08080";
        const HexStr ORANGERED             = "FF4500";
        const HexStr NAVAJOWHITE           = "FFDEAD";
        const HexStr LIME                  = "00FF00";
        const HexStr PALEGREEN             = "98FB98";
        const HexStr DARKSLATEGREY         = "2F4F4F";
        const HexStr GREENYELLOW           = "ADFF2F";
        const HexStr BURLYWOOD             = "DEB887";
        const HexStr SEASHELL              = "FFF5EE";
        const HexStr MEDIUMSPRINGGREEN     = "00FA9A";
        const HexStr FUCHSIA               = "FF00FF";
        const HexStr PAPAYAWHIP            = "FFEFD5";
        const HexStr BLANCHEDALMOND        = "FFEBCD";
        const HexStr CHARTREUSE            = "7FFF00";
        const HexStr DIMGRAY               = "696969";
        const HexStr BLACK                 = "000000";
        const HexStr PEACHPUFF             = "FFDAB9";
        const HexStr SPRINGGREEN           = "00FF7F";
        const HexStr AQUAMARINE            = "7FFFD4";
        const HexStr WHITE                 = "FFFFFF";
        const HexStr ORANGE                = "FFA500";
        const HexStr LIGHTSALMON           = "FFA07A";
        const HexStr DARKSLATEGRAY         = "2F4F4F";
        const HexStr BROWN                 = "A52A2A";
        const HexStr IVORY                 = "FFFFF0";
        const HexStr DODGERBLUE            = "1E90FF";
        const HexStr PERU                  = "CD853F";
        const HexStr LAWNGREEN             = "7CFC00";
        const HexStr CHOCOLATE             = "D2691E";
        const HexStr CRIMSON               = "DC143C";
        const HexStr FORESTGREEN           = "228B22";
        const HexStr DARKGREY              = "A9A9A9";
        const HexStr LIGHTSEAGREEN         = "20B2AA";
        const HexStr CYAN                  = "00FFFF";
        const HexStr MINTCREAM             = "F5FFFA";
        const HexStr SILVER                = "C0C0C0";
        const HexStr ANTIQUEWHITE          = "FAEBD7";
        const HexStr MEDIUMORCHID          = "BA55D3";
        const HexStr SKYBLUE               = "87CEEB";
        const HexStr GRAY                  = "808080";
        const HexStr DARKTURQUOISE         = "00CED1";
        const HexStr GOLDENROD             = "DAA520";
        const HexStr DARKGREEN             = "006400";
        const HexStr FLORALWHITE           = "FFFAF0";
        const HexStr DARKVIOLET            = "9400D3";
        const HexStr DARKGRAY              = "A9A9A9";
        const HexStr MOCCASIN              = "FFE4B5";
        const HexStr SADDLEBROWN           = "8B4513";
        const HexStr GREY                  = "808080";
        const HexStr DARKSLATEBLUE         = "483D8B";
        const HexStr LIGHTSKYBLUE          = "87CEFA";
        const HexStr LIGHTPINK             = "FFB6C1";
        const HexStr MEDIUMVIOLETRED       = "C71585";
        const HexStr SLATEGREY             = "708090";
        const HexStr RED                   = "FF0000";
        const HexStr DEEPPINK              = "FF1493";
        const HexStr LIMEGREEN             = "32CD32";
        const HexStr DARKMAGENTA           = "8B008B";
        const HexStr PALEGOLDENROD         = "EEE8AA";
        const HexStr PLUM                  = "DDA0DD";
        const HexStr TURQUOISE             = "40E0D0";
        const HexStr LIGHTGREY             = "D3D3D3";
        const HexStr LIGHTGOLDENRODYELLOW  = "FAFAD2";
        const HexStr DARKGOLDENROD         = "B8860B";
        const HexStr LAVENDER              = "E6E6FA";
        const HexStr MAROON                = "800000";
        const HexStr YELLOWGREEN           = "9ACD32";
        const HexStr SANDYBROWN            = "F4A460";
        const HexStr THISTLE               = "D8BFD8";
        const HexStr VIOLET                = "EE82EE";
        const HexStr NAVY                  = "000080";
        const HexStr MAGENTA               = "FF00FF";
        const HexStr DIMGREY               = "696969";
        const HexStr TAN                   = "D2B48C";
        const HexStr ROSYBROWN             = "BC8F8F";
        const HexStr OLIVEDRAB             = "6B8E23";
        const HexStr BLUE                  = "0000FF";
        const HexStr LIGHTBLUE             = "ADD8E6";
        const HexStr GHOSTWHITE            = "F8F8FF";
        const HexStr HONEYDEW              = "F0FFF0";
        const HexStr CORNFLOWERBLUE        = "6495ED";
        const HexStr SLATEBLUE             = "6A5ACD";
        const HexStr LINEN                 = "FAF0E6";
        const HexStr DARKBLUE              = "00008B";
        const HexStr POWDERBLUE            = "B0E0E6";
        const HexStr SEAGREEN              = "2E8B57";
        const HexStr DARKKHAKI             = "BDB76B";
        const HexStr SNOW                  = "FFFAFA";
        const HexStr SIENNA                = "A0522D";
        const HexStr MEDIUMBLUE            = "0000CD";
        const HexStr ROYALBLUE             = "4169E1";
        const HexStr LIGHTCYAN             = "E0FFFF";
        const HexStr GREEN                 = "008000";
        const HexStr MEDIUMPURPLE          = "9370DB";
        const HexStr MIDNIGHTBLUE          = "191970";
        const HexStr CORNSILK              = "FFF8DC";
        const HexStr PALETURQUOISE         = "AFEEEE";
        const HexStr BISQUE                = "FFE4C4";
        const HexStr SLATEGRAY             = "708090";
        const HexStr DARKCYAN              = "008B8B";
        const HexStr KHAKI                 = "F0E68C";
        const HexStr WHEAT                 = "F5DEB3";
        const HexStr TEAL                  = "008080";
        const HexStr DARKORCHID            = "9932CC";
        const HexStr DEEPSKYBLUE           = "00BFFF";
        const HexStr SALMON                = "FA8072";
        const HexStr DARKRED               = "8B0000";
        const HexStr STEELBLUE             = "4682B4";
        const HexStr PALEVIOLETRED         = "DB7093";
        const HexStr LIGHTSLATEGRAY        = "778899";
        const HexStr ALICEBLUE             = "F0F8FF";
        const HexStr LIGHTSLATEGREY        = "778899";
        const HexStr LIGHTGREEN            = "90EE90";
        const HexStr ORCHID                = "DA70D6";
        const HexStr GAINSBORO             = "DCDCDC";
        const HexStr MEDIUMSEAGREEN        = "3CB371";
        const HexStr LIGHTGRAY             = "D3D3D3";
        const HexStr MEDIUMTURQUOISE       = "48D1CC";
        const HexStr LEMONCHIFFON          = "FFFACD";
        const HexStr CADETBLUE             = "5F9EA0";
        const HexStr LIGHTYELLOW           = "FFFFE0";
        const HexStr LAVENDERBLUSH         = "FFF0F5";
        const HexStr CORAL                 = "FF7F50";
        const HexStr PURPLE                = "800080";
        const HexStr AQUA                  = "00FFFF";
        const HexStr WHITESMOKE            = "F5F5F5";
        const HexStr MEDIUMSLATEBLUE       = "7B68EE";
        const HexStr DARKORANGE            = "FF8C00";
        const HexStr MEDIUMAQUAMARINE      = "66CDAA";
        const HexStr DARKSALMON            = "E9967A";
        const HexStr BEIGE                 = "F5F5DC";
        const HexStr BLUEVIOLET            = "8A2BE2";
        const HexStr AZURE                 = "F0FFFF";
        const HexStr LIGHTSTEELBLUE        = "B0C4DE";
        const HexStr OLDLACE               = "FDF5E6";
        const HexStr REBECCAPURPLE         = "663399";
    }

    /* Some functions to make Chromatic4Cpp useful and workable. */
    namespace HelperUtils  {
        using namespace BaseTypes;
        
        template<class T> void PrintLine(T t) {
            std::cout << t << std::endl;
        }
        bool CheckHexChar(HexBit hex);
        HexStr AutoConvertHexStr(const HexStr&);
        HexStr SkipInvalidHexStr(const HexStr&);
        bool StrictCheckHexStr(const HexStr&);
        unsigned char GetChannelModeSize(ChannelNumMode);
        void AutoFillHexStr(HexStr&, ChannelNumMode, const HexStr&);
        const char* GetChannelModeName(ChannelNumMode);
        const char* GetCheckModeName(HexCheckMode);
        const char* GetChannelInputModeName(RGBAChannelInputMode);
        HexBit UpperCaseChar(HexBit);
        HexBit LowerCaseChar(HexBit);
        void UpperCaseStr(HexStr&);
        void LowerCaseStr(HexStr&);
        unsigned long Hex2Number(const HexStr&);
    }
    
    
    /* Some data structions definition, like Hex, RGB, RGBA, and so on. */
    namespace DataFrame {
        using namespace BaseTypes;
        using namespace HexColor;
        using namespace HelperUtils;
        
        struct HexFrame {
            HexStr hex;
            ChannelNumMode channelMode;
            HexCheckMode checkMode;
            
            HexFrame() {
                hex = BLACK;
                channelMode = eChannelNumMode3;
                checkMode = eHexCheckModeAutoConvert;
            }
            
            HexFrame(HexStr _hex, ChannelNumMode _channelMode, HexCheckMode _checkMode ) {
                hex = _hex;
                channelMode = _channelMode;
                checkMode = _checkMode;
            }
            
            HexFrame Clone() {
                return HexFrame(hex, channelMode, checkMode);
            }
            
            HexFrame Dump() {
                char txt[80];
                memset(txt, 0, sizeof(txt));
                string sub = hex.substr(0, hex.size());
                UpperCaseStr(sub);
                sprintf(txt, "Hex='#%s' CheckMode='%s' ChannelMode='%s'",
                        sub.c_str(),// Uppercase as default
                        GetCheckModeName(checkMode),
                        GetChannelModeName(channelMode)
                        );
                PrintLine(txt);
                return *this;
            }
        };
        
        struct sRGBFrame {
        public:
            RGBit r, g, b;
            RGBAChannelInputMode inputMode;
            
            sRGBFrame()
            { r = 0; g = 0; b = 0; inputMode=eRGBAChannelInputModeInteger; }
            sRGBFrame(RGBit _r, RGBit _g, RGBit _b, RGBAChannelInputMode _input=eRGBAChannelInputModeInteger)
            { r = _r; g = _g; b = _b; CheckInputMode(_input); }
            int Red()   { return r; }
            int Green() { return g; }
            int Blue()  { return b; }
            sRGBFrame Red(RGBit _r)   { r = _r; return *this; }
            sRGBFrame Green(RGBit _g) { g = _g; return *this; }
            sRGBFrame Blue(RGBit _b)  { b = _b; return *this; }
            sRGBFrame Dump() {
                char txt[64];
                memset(txt, 0, sizeof(txt));
                sprintf(txt, "sRGB='%d,%d,%d' InputMode='%s'",
                        r, g, b,
                        GetChannelInputModeName(inputMode));
                PrintLine(txt);
                return *this;
            }
            sRGBFrame DumpAsFloat() {
                char txt[96];
                memset(txt, 0, sizeof(txt));
                sprintf(txt, "sRGB='%.03f,%.3f,%.03f' InputMode='%s'",
                        r/255.f,g/255.f,b/255.f,
                        GetChannelInputModeName(inputMode));
                PrintLine(txt);
                return *this;
            }
            
            void CheckInputMode(RGBAChannelInputMode mode) {
                if(inputMode == eRGBAChannelInputModeAlphaFloat)
                    inputMode = eRGBAChannelInputModeFloat;
                else
                    inputMode = mode;
            }
        };
        
        struct sRGBAFrame : public sRGBFrame {
        public:
            RGBit a;
            sRGBAFrame() {
                sRGBFrame();
                a = 255;
            }
            sRGBAFrame(RGBit _r, RGBit _g, RGBit _b) {
                sRGBFrame(_r, _g, _b);
                a = 255;
            }
            sRGBAFrame(RGBit _r, RGBit _g, RGBit _b, RGBit _a) {
                sRGBFrame(_r, _g, _b);
                a = _a;
            }
            int Red()   { return r; }
            int Green() { return g; }
            int Blue()  { return b; }
            int Alpha() { return a; }
            sRGBAFrame Red(RGBit _r)   { r = _r; return *this; }
            sRGBAFrame Green(RGBit _g) { g = _g; return *this; }
            sRGBAFrame Blue(RGBit _b)  { b = _b; return *this; }
            sRGBAFrame Alpha(RGBit _a) { a = _a; return *this; }
            sRGBAFrame Dump() {
                char txt[64];
                memset(txt, 0, sizeof(txt));
                sprintf(txt, "sRGBA='%d,%d,%d,%d' InputMode='%s'",
                        r,g,b,a,
                        GetChannelInputModeName(inputMode));
                PrintLine(txt);
                return *this;
            }
            sRGBFrame DumpAsFloat() {
                char txt[96];
                memset(txt, 0, sizeof(txt));
                sprintf(txt, "sRGBA='%.03f,%.3f,%.03f,%.03f' InputMode='%s'",
                        r/255.f,g/255.f,b/255.f,a/255.f,
                        GetChannelInputModeName(inputMode));
                PrintLine(txt);
                return *this;
            }
            sRGBFrame DumpAlphaFloat() {
                char txt[64];
                memset(txt, 0, sizeof(txt));
                sprintf(txt, "sRGBA='%d,%d,%d,%.03f' InputMode='%s'",
                        r,g,b,a/255.f,
                        GetChannelInputModeName(inputMode));
                PrintLine(txt);
                return *this;
            }
        };
    }

    

    
    //Hex Color Value Definition
    namespace ColorSpace {
        using namespace BaseTypes;
        using namespace DataFrame;
        
        class HEX {
        private:
            HexFrame _hexFrame;
            
        public:
            HEX();
            HEX(HexStr);
            HEX(HexStr, ChannelNumMode);
            HEX(HexStr, HexCheckMode);
            HEX(HexStr, ChannelNumMode, HexCheckMode);
            HEX(HexFrame& other);
            
            HEX Dump();
            
            HexStr Get();
            HEX Set(HexStr str);
            HexFrame GetHexFrame();
            HEX SetHexFrame(HexFrame& other);

            ChannelNumMode GetChannelMode();
            HEX SetChannelMode(ChannelNumMode mode);
            
            HexCheckMode GetCheckMode();
            HEX SetCheckMode(HexCheckMode mode);
            
            int GetChannelDecNum(HexBit channel);
            sRGBFrame RGBFrame();
            sRGBAFrame RGBAFrame();
            
        private:
            void _Set(HexStr hex);
        };
        
        
        class RGB {
        private:
            sRGBFrame _frame;
        public:
            RGB();
            RGB(RGBit, RGBit, RGBit, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
            RGB(HexStr, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
            RGB(HEX, RGBAChannelInputMode mode = eRGBAChannelInputModeInteger);
            RGB(sRGBFrame);
            
            RGB Set(sRGBFrame);
            RGB Set(RGBit, RGBit, RGBit);
            RGB Dump();
            RGBAChannelInputMode GetChannelInputMode();
            RGB SetChannelInputMode(RGBAChannelInputMode);
        private:
            void _Set(sRGBFrame);
        };
        
        
        struct RGBA;
        struct CMYK;
        struct HSL;
        struct HSV;
        struct YUV;
        struct LAB;
    }
    
    
}

#endif /* Chromatic4Cpp_hpp */
