# [COM-ADC](https://github.com/OS-Q/D1)

[![sites](OS-Q/OS-Q.png)](http://www.OS-Q.com)

#### 归属嵌入模块：[W1](https://github.com/OS-Q/W1)

#### 关于系统架构：[OS-Q](https://github.com/OS-Q/OS-Q)

Edge-Q -> 体系 Q[1,4] -> 节点 M[1,12] -> 平台 W[1,52] -> 设备 D[1,365]

### [设备描述](https://github.com/OS-Q/D1/wiki) 

COM-ADC嵌入设备，通过嵌入到传感器内部采集数据并通过固定的协议格式将数据传出，实现上位机的自适应获得。

[Edge-D1](https://github.com/OS-Q/D1)工程定义的核心在于标准化的上层通信和驱动逻辑，同时可快速替换的采集逻辑，实现平台的功能特性。

### [开放资源](https://github.com/OS-Q/)

* [文档](docs/)
* [工程](project/)
	* [ISP工程](project/ISP)
	* [keil工程](project/keil)

### [平台资源](https://github.com/sochub)

目前定义的[Edge-D1](https://github.com/OS-Q/D1)设备采用QFN封装单片机（单主控），主要采用新唐的8051单片机N76E003作为主控核心，也是D1设备中唯一的程单元，相关的设计资料和选型方案优劣可查阅
[SoC资源平台](https://github.com/sochub)

* [N76E003](https://github.com/sochub/N76E003)

后续稳定后可能添加其他的替代方案

### [设备结构](https://github.com/OS-Q/W1)

* W1：[嵌入模块](https://github.com/OS-Q/W1)
	* D1：COM-ADC
	* D2：[COM-IIC](https://github.com/OS-Q/D2)
	* D3：[COM-COM](https://github.com/OS-Q/D3)
	* D4：[COM-CNT](https://github.com/OS-Q/D4)
	* D5：[COM-IRQ](https://github.com/OS-Q/D5)
	* D6：[USB-DRV](https://github.com/OS-Q/D6)
	* D7：[RF-LP](https://github.com/OS-Q/D7)

### [OS-Q : Operation System for edge devices](http://www.OS-Q.com/Edge/D1)
####  2019-5-29