# 设计
## 概要
准备分成几层
1. hardware layer.
	- 用于抽象各个平台的硬件特征, io ports, dma, spi, iic
2. interface layer
	- 对底层提供一个统一的抽象, ...
3. micro kernel层
	- micro kernel
4. service 层
	- driver, fs 
5. program 层
	- 各种程序所在的层

1,2,3 三层准备用c和汇编写
4,5 准备用高级语言，类似ruby来写

这是个实验

