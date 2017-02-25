//
//  Chromatic4Cpp_BaseTypes.hpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#ifndef Chromatic4Cpp_BaseTypes_hpp
#define Chromatic4Cpp_BaseTypes_hpp

/* Base data types definition */
typedef enum {
    eCS_HEX,    // completed 90%
    eCS_RGB,    // completed 90%
    eCS_RGBA,   // completed 70%
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


typedef const char*     CStr;
typedef std::string     HexStr;
typedef unsigned char   HexBit;
typedef unsigned char   RGBit;
typedef float           RGBitf;
typedef float           CMYKBit;
typedef float           HSLBit;
typedef float           HSVBit;
typedef unsigned short  HueBit;

#define RGB_MAX     255
#define RGB_MIN     0
#define RGBA_MAX    255
#define RGBA_MIN    0


#endif /* Chromatic4Cpp_BaseTypes_hpp */
