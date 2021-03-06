//
//  Chromatic4Cpp_RGB.cpp
//  Chromatic4Cpp-Redesign
//
//  Created by Reyn-Mac on 2017/2/23.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//

#include "Chromatic4Cpp.hpp"

using namespace Chromatic4Cpp;
using namespace HelperUtils;
using namespace ColorSpace;
using namespace DataFrame;
using namespace HexColor;
using namespace BaseTypes;

RGB* RGB::_instance = NULL;

RGB::RGB() {
    sRGBFrame frame = sRGBFrame(0,0,0);
    Set(frame);
}

RGB::RGB(RGBit r, RGBit g, RGBit b, RGBAChannelInputMode mode) {
    sRGBFrame frame = sRGBFrame(r,g,b);
    Set(frame);
}

RGB::RGB(HEX hex, RGBAChannelInputMode mode) {
    sRGBFrame frame = hex.RGBFrame();
    frame.inputMode = mode;
    Set(frame);
}

RGB::RGB(sRGBFrame& frame) {
    Set(frame);
}

RGB::RGB(HexStr hex, RGBAChannelInputMode mode) {
    sRGBFrame frame = HEX(hex).RGBFrame();
    frame.inputMode = mode;
    Set(frame);
}

RGB& RGB::Set(sRGBFrame& frame) {
    _Set(frame);
    return *this;
}

RGB& RGB::Set(RGBit r, RGBit g, RGBit b) {
    sRGBFrame frame = sRGBFrame(r,g,b);
    return Set(frame);
}

void RGB::_Set(sRGBFrame& frame) {
    frame.CheckInputMode(frame.inputMode);
    _frame = frame;
}

RGB& RGB::Dump() {
    if(_frame.inputMode == eRGBAChannelInputModeFloat)
        _frame.DumpAsFloat();
    else
        _frame.Dump();
    return *this;
}

RGB& RGB::SetChannelInputMode(RGBAChannelInputMode mode) {
    _frame.CheckInputMode(mode);
    return *this;
}

RGBAChannelInputMode RGB::GetChannelInputMode() {
    return _frame.inputMode;
}

const HexStr RGB::HexString() {
    HexStr ret;
    ret.clear();
    ret.append(Number2Hex(_frame.Red()));
    ret.append(Number2Hex(_frame.Green()));
    ret.append(Number2Hex(_frame.Blue()));
    return ret;
}

HEX RGB::AsHEX() {
    return HEX(HexString());
}
