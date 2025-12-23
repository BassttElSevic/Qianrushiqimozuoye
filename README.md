# 嵌入式系统基础作业

Basstt的嵌入式期末作业

## 项目概述

本项目是一个嵌入式系统基础作业，包含了以下核心功能模块：

- **GPIO控制**: LED闪烁、按钮输入
- **串口通信**: USART收发数据
- **定时器**: 定时中断和延时功能

## 快速开始

### 编译项目

```bash
# 编译所有示例
make

# 编译特定示例
make led_blink
make button_input
make usart_example
make timer_example
```

### 项目结构

```
├── include/          # 头文件
├── src/              # 源代码
├── build/            # 编译输出
├── docs/             # 详细文档
└── Makefile          # 编译脚本
```

## 功能模块

| 模块 | 文件 | 功能描述 |
|------|------|----------|
| GPIO | gpio.h/c | 数字输入输出控制 |
| USART | usart.h/c | 串口通信 |
| Timer | timer.h/c | 定时器和延时 |

## 示例程序

- `led_blink.c` - LED闪烁示例
- `button_input.c` - 按钮输入示例
- `usart_example.c` - 串口通信示例
- `timer_example.c` - 定时器中断示例

## 详细文档

查看 [docs/README_CN.md](docs/README_CN.md) 获取完整的项目文档，包括：
- 详细的功能说明
- 硬件连接指南
- 烧录方法
- 学习重点

## 硬件平台

本项目基于STM32F103C8T6微控制器（蓝色药丸开发板）

## 作者

Basstt
