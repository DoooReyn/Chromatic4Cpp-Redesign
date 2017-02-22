//
//  Chromatic4Cpp_Hex.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/2/21.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatic4Cpp.hpp"

using namespace Chromatic4Cpp;
using namespace HelperUtils;
using namespace ColorSpace;
using namespace DataFrame;
using namespace HexColor;
using namespace BaseTypes;

/****************************************************************************************************************************************
 * HEX ColorSpace Implementation
 ****************************************************************************************************************************************/

HEX::HEX() {}

HEX::HEX(HexStr hex) {
    Set(hex);
}

HEX::HEX(HexStr hex, ChannelNumMode mode) {
    _hexFrame.channelMode = mode;
    _hexFrame.checkMode   = eHexCheckModeAutoConvert;
    Set(hex);
}

HEX::HEX(HexStr hex, HexCheckMode mode) {
    _hexFrame.checkMode   = mode;
    _hexFrame.channelMode = eChannelNumMode3;
    Set(hex);
}

HEX::HEX(HexStr hex, ChannelNumMode channel, HexCheckMode check) {
    _hexFrame.checkMode   = check;
    _hexFrame.channelMode = channel;
    Set(hex);
}

HEX::HEX(HexFrame& other) {
    SetHexFrame(other);
}

HEX HEX::Dump() {
    _hexFrame.Dump();
    return *this;
}

HexStr HEX::Get() {
    return _hexFrame.hex.substr(0, _hexFrame.hex.size());
}

HEX HEX::Set(HexStr hex) {
    switch (_hexFrame.checkMode) {
        case eHexCheckModeAutoConvert:
            _Set(AutoConvertHexStr(hex));
            break;
        case eHexCheckModeSkipInvalid:
            _Set(SkipInvalidHexStr(hex));
            break;
        case eHexCheckModeStrictCheck:
            StrictCheckHexStr(hex);
        default:
            break;
    }
    return *this;
}

HexFrame HEX::GetHexFrame() {
    return _hexFrame.Clone();
}

HEX HEX::SetHexFrame(HexFrame& other) {
    _hexFrame = other;
    Set(_hexFrame.hex);
    return *this;
}

void HEX::_Set(HexStr hex) {
    AutoFillHexStr(hex, _hexFrame.channelMode, "0");
    _hexFrame.hex = hex;
}

ChannelNumMode HEX::GetChannelMode() {
    return _hexFrame.channelMode;
}

HEX HEX::SetChannelMode(ChannelNumMode mode) {
    _hexFrame.channelMode = mode;
    Set(_hexFrame.hex);
    return *this;
}

HexCheckMode HEX::GetCheckMode() {
    return _hexFrame.checkMode;
}

HEX HEX::SetCheckMode(HexCheckMode mode) {
    _hexFrame.checkMode = mode;
    Set(_hexFrame.hex);
    return *this;
}

int HEX::GetChannelDecNum(HexBit channel) {
    if(channel < 1 || channel > 4) return 0;
    return (int)Hex2Number(_hexFrame.hex.substr((channel-1)*2, 2));
}

sRGBFrame HEX::RGBFrame() {
    sRGBFrame frame;
    frame.r = GetChannelDecNum(1);
    frame.g = GetChannelDecNum(2);
    frame.b = GetChannelDecNum(3);
    return frame;
}

sRGBAFrame HEX::RGBAFrame() {
    sRGBAFrame frame;
    frame.r = GetChannelDecNum(1);
    frame.g = GetChannelDecNum(2);
    frame.b = GetChannelDecNum(3);
    frame.a = GetChannelDecNum(4);
    return frame;
}
