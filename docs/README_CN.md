# 嵌入式系统基础作业

本项目是Basstt的嵌入式系统基础作业，包含了嵌入式系统开发的基本示例。

## 项目简介

本项目演示了嵌入式系统开发中的常见功能模块，适用于STM32系列微控制器（以STM32F103为例）。

## 功能模块

### 1. GPIO（通用输入输出）
- **文件**: `include/gpio.h`, `src/gpio.c`
- **功能**: 
  - GPIO引脚初始化
  - 数字输出控制（设置高/低电平）
  - 数字输入读取
  - 引脚电平翻转

### 2. USART（串口通信）
- **文件**: `include/usart.h`, `src/usart.c`
- **功能**:
  - 串口初始化（支持多种波特率）
  - 字符发送与接收
  - 字符串发送

### 3. Timer（定时器）
- **文件**: `include/timer.h`, `src/timer.c`
- **功能**:
  - 定时器初始化与配置
  - 定时器启动与停止
  - 延时函数（毫秒级和微秒级）

## 示例程序

### 1. LED闪烁示例 (`led_blink.c`)
演示如何使用GPIO控制LED灯闪烁。

**功能**:
- LED每隔500ms闪烁一次
- 使用延时函数实现定时

**引脚配置**:
- LED连接到GPIOC的13号引脚

### 2. 按钮输入示例 (`button_input.c`)
演示如何读取按钮输入并控制LED。

**功能**:
- 检测按钮按下事件
- 每次按下按钮，LED状态翻转
- 包含简单的消抖处理

**引脚配置**:
- 按钮连接到GPIOA的0号引脚
- LED连接到GPIOC的13号引脚

### 3. 串口通信示例 (`usart_example.c`)
演示如何使用USART进行串口通信。

**功能**:
- 发送欢迎信息
- 接收用户输入的字符
- 回显接收到的字符

**配置**:
- 使用USART1
- 波特率：115200

### 4. 定时器示例 (`timer_example.c`)
演示如何使用定时器产生定时中断。

**功能**:
- 配置定时器产生1ms周期中断
- 在中断中实现LED的1秒闪烁

**配置**:
- 使用TIM2
- 中断周期：1ms

## 项目结构

```
Qianrushiqimozuoye/
├── include/           # 头文件目录
│   ├── gpio.h        # GPIO模块头文件
│   ├── usart.h       # USART模块头文件
│   └── timer.h       # Timer模块头文件
├── src/              # 源文件目录
│   ├── gpio.c        # GPIO模块实现
│   ├── usart.c       # USART模块实现
│   ├── timer.c       # Timer模块实现
│   ├── led_blink.c   # LED闪烁示例
│   ├── button_input.c    # 按钮输入示例
│   ├── usart_example.c   # 串口通信示例
│   └── timer_example.c   # 定时器示例
├── build/            # 编译输出目录
├── docs/             # 文档目录
├── Makefile          # 编译脚本
└── README.md         # 项目说明文件
```

## 编译说明

### 前提条件

需要安装ARM GCC工具链：
```bash
# Ubuntu/Debian
sudo apt-get install gcc-arm-none-eabi

# macOS
brew install gcc-arm-embedded
```

### 编译命令

```bash
# 编译所有示例
make

# 编译特定示例
make led_blink
make button_input
make usart_example
make timer_example

# 清理编译文件
make clean

# 查看帮助
make help
```

### 编译输出

编译后会在`build/`目录下生成以下文件：
- `.elf` - ELF格式可执行文件（用于调试）
- `.bin` - 二进制文件（用于烧录）
- `.hex` - Intel HEX格式文件（用于烧录）

## 烧录说明

可以使用以下工具将编译后的程序烧录到STM32：

1. **ST-Link**:
   ```bash
   st-flash write build/led_blink.bin 0x8000000
   ```

2. **J-Link**:
   ```bash
   JLinkExe -device STM32F103C8 -if SWD -speed 4000 -autoconnect 1
   ```

3. **OpenOCD**:
   ```bash
   openocd -f interface/stlink.cfg -f target/stm32f1x.cfg \
           -c "program build/led_blink.elf verify reset exit"
   ```

## 硬件连接

### STM32F103C8T6 (蓝色药丸板)
- **LED**: PC13（板载LED）
- **按钮**: PA0
- **USART1**:
  - TX: PA9
  - RX: PA10

## 学习重点

1. **GPIO控制**: 理解数字IO的基本操作
2. **中断处理**: 理解外部中断和定时器中断
3. **串口通信**: 掌握USART的基本使用
4. **定时器应用**: 理解定时器的配置和使用
5. **寄存器操作**: 理解底层寄存器的直接操作

## 扩展学习

- 添加PWM（脉宽调制）功能
- 实现ADC（模数转换）采集
- 添加I2C或SPI通信
- 实现低功耗模式
- 添加RTOS（实时操作系统）

## 注意事项

1. 本项目代码直接操作硬件寄存器，实际项目中建议使用HAL库或标准外设库
2. 延时函数是简单的空循环实现，不够精确，实际应用应使用定时器
3. 中断服务函数需要在启动文件中正确配置
4. 确保硬件连接正确，避免短路或接错引脚

## 参考资料

- STM32F103数据手册
- ARM Cortex-M3权威指南
- 《嵌入式系统设计》课程教材

## 作者

Basstt

## 许可证

本项目仅用于学习目的。
