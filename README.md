# Chromatic4Cpp-Redesign
**Chromatic4Cpp-Redesign** 的原身是 [Chromatic4Cpp](https://github.com/DoooReyn/Chromatic4cpp)，二者想要达成的目标是的一致的；但从[Chromatic4Cpp](https://github.com/DoooReyn/Chromatic4cpp)来看，存在不少代码混乱和冗余的问题，因此 **Chromatic4Cpp-Redesign** 针对命名空间和一些数据结构进行了重新设计，此外，也会优化或简化许多操作。**Chromatic4Cpp-Redesign** 项目将会持续更新，感谢关注。

## 更新列表
**2017-02-22**
- 全新设计的 `Chromatic4Cpp` 色彩空间；
- 新增十六进制数据结构；
- 新增用于十六进制数据构造和转换的 `HEX` 类；
- 新增 `HEX` 类的测试用例，详见 [tests/TestCase_HEX.cpp](https://github.com/DoooReyn/Chromatic4Cpp-Redesign/blob/master/tests/TestCase_HEX.cpp)；
- 及其他...

**2017-02-23**
- 新增 `sRGBFrame` 和 `sRGBAFrame` 数据结构，分别用于存储和处理 `RGB`，`RGBA` 各通道数据；
- 新增 `HEX` 获取 `sRGBFrame` 和 `sRGBAFrame` 的接口；
- 增加 `Chromatic4Cpp` 色彩空间的文档说明和部分注释；
