
# STM32F103 嵌入式系统项目 / STM32F103 Embedded Systems Project

[中文](#中文) | [English](#english)

---

<a name="中文"></a>
## 中文说明

### 项目简介

这是一个基于 **STM32F103ZET6** 微控制器的嵌入式系统项目，集成了多种传感器和外设，实现了温湿度监测、光照检测、LCD显示和串口通信等功能。该项目使用 STM32 HAL 库开发，采用 CMake 构建系统。

### 硬件要求

- **主控芯片**: STM32F103ZET6 (ARM Cortex-M3)
- **传感器模块**:
  - DHT11 温湿度传感器 (GPIO: PG11)
  - PCF8591 AD/DA转换模块 (I2C接口，用于光敏电阻和温度传感)
- **显示模块**: TFT LCD 显示屏 (通过 FSMC 接口连接)
- **指示灯**: LED0 和 LED1
- **通信接口**: 
  - USART1 和 USART2 (串口通信)
  - I2C1 和 I2C2
- **其他外设**: 
  - ADC3 (模拟数字转换器)
  - TIM1 (定时器)

### 软件要求

- **构建工具**: CMake (>= 3.22)
- **编译器**: ARM GCC 交叉编译工具链
- **开发环境**: 
  - STM32CubeMX (用于外设配置)
  - CLion / VSCode / 其他支持 CMake 的 IDE
- **调试工具**: ST-Link 或 J-Link

### 主要功能

1. **温湿度监测**: 通过 DHT11 传感器实时读取环境温湿度数据
2. **光照检测**: 使用 PCF8591 ADC 读取光敏电阻值，监测环境光照强度
3. **温度监测**: 通过 PCF8591 另一路 ADC 输入读取温度传感器数据
4. **LCD 显示**: 
   - 支持中文字符显示
   - 显示温度、湿度、光照强度等实时数据
   - 支持图形绘制（圆形等）
   - 启动动画和欢迎界面
5. **LED 控制**: 可控制 LED 闪烁，提供状态指示
6. **串口通信**: 通过 UART 发送传感器数据到上位机
7. **蜂鸣器控制**: GPIO PB8 控制蜂鸣器输出

### 项目结构

```
.
├── CMakeLists.txt              # CMake 构建配置文件
├── CMakePresets.json           # CMake 预设配置
├── README.md                   # 项目说明文档
├── chuanchuankou.ioc          # STM32CubeMX 配置文件
├── STM32F103XX_FLASH.ld       # 链接脚本
├── startup_stm32f103xe.s      # 启动文件
├── Core/                       # 核心源代码
│   ├── Src/                    # C 源文件
│   │   ├── main.c             # 主程序
│   │   ├── gpio.c             # GPIO 配置
│   │   ├── i2c.c              # I2C 配置
│   │   ├── usart.c            # USART 配置
│   │   ├── adc.c              # ADC 配置
│   │   └── ...
│   ├── Inc/                    # 头文件
│   ├── DHT11/                  # DHT11 驱动
│   │   ├── dht11.c
│   │   └── dht11.h
│   └── LCD/                    # LCD 驱动
│       ├── lcd.c
│       ├── lcd.h
│       ├── tct.c              # LCD 图像数据 (720x720 像素图像数组)
│       └── ...
├── Drivers/                    # STM32 HAL 驱动库
│   ├── STM32F1xx_HAL_Driver/
│   └── CMSIS/
└── cmake/                      # CMake 辅助文件
```

### 构建说明

#### 1. 克隆仓库

```bash
git clone https://github.com/BassttElSevic/Qianrushiqimozuoye.git
cd Qianrushiqimozuoye
```

#### 2. 配置 CMake

```bash
cmake -B build -S .
```

#### 3. 编译项目

```bash
cmake --build build
```

#### 4. 烧录程序

使用 ST-Link 或其他下载工具将生成的 `.bin` 或 `.hex` 文件烧录到 STM32F103ZET6 开发板。

### 引脚配置

| 外设 | 引脚 | 功能 |
|------|------|------|
| DHT11 | PG11 | 数据线 |
| PCF8591 | I2C2 (SCL/SDA) | I2C 通信 |
| LCD | FSMC | 数据和控制线 |
| LED0 | PB5 | 状态指示 |
| LED1 | PE5 | 状态指示 |
| 蜂鸣器 | PB8 | 输出控制 |
| USART1 | TX/RX | 串口通信 |

### 使用说明

1. **上电启动**: 系统上电后，LCD 将显示启动动画和欢迎信息
2. **传感器数据显示**: LCD 实时显示温度、湿度和光照强度
3. **串口监控**: 通过串口助手（波特率根据配置）可以接收传感器数据
4. **中断触发**: 支持通过外部中断（按键等）切换显示模式

### 开发者信息

- **学号**: 20252738, 20251643
- **开发日期**: 2025年

### 许可证

本项目使用的 STM32 HAL 库遵循 ST 的许可证条款。项目其他部分可根据需要使用。

---

<a name="english"></a>
## English Documentation

### Project Overview

This is an embedded systems project based on the **STM32F103ZET6** microcontroller, integrating multiple sensors and peripherals to implement temperature and humidity monitoring, light detection, LCD display, and UART communication. The project is developed using the STM32 HAL library and built with CMake.

### Hardware Requirements

- **Main Controller**: STM32F103ZET6 (ARM Cortex-M3)
- **Sensor Modules**:
  - DHT11 Temperature & Humidity Sensor (GPIO: PG11)
  - PCF8591 AD/DA Converter Module (I2C interface for photoresistor and temperature sensing)
- **Display Module**: TFT LCD Screen (connected via FSMC interface)
- **Indicators**: LED0 and LED1
- **Communication Interfaces**: 
  - USART1 and USART2 (Serial communication)
  - I2C1 and I2C2
- **Other Peripherals**: 
  - ADC3 (Analog-to-Digital Converter)
  - TIM1 (Timer)

### Software Requirements

- **Build Tool**: CMake (>= 3.22)
- **Compiler**: ARM GCC Cross-compilation Toolchain
- **Development Environment**: 
  - STM32CubeMX (for peripheral configuration)
  - CLion / VSCode / Other CMake-compatible IDEs
- **Debug Tools**: ST-Link or J-Link

### Main Features

1. **Temperature & Humidity Monitoring**: Real-time reading of environmental temperature and humidity data via DHT11 sensor
2. **Light Detection**: Using PCF8591 ADC to read photoresistor values and monitor ambient light intensity
3. **Temperature Monitoring**: Reading temperature sensor data through another ADC channel of PCF8591
4. **LCD Display**: 
   - Supports Chinese character display
   - Displays real-time data including temperature, humidity, and light intensity
   - Supports graphics drawing (circles, etc.)
   - Startup animation and welcome screen
5. **LED Control**: Controllable LED blinking for status indication
6. **Serial Communication**: Sends sensor data to host computer via UART
7. **Buzzer Control**: GPIO PB8 controls buzzer output

### Project Structure

```
.
├── CMakeLists.txt              # CMake build configuration
├── CMakePresets.json           # CMake preset configuration
├── README.md                   # Project documentation
├── chuanchuankou.ioc          # STM32CubeMX configuration file
├── STM32F103XX_FLASH.ld       # Linker script
├── startup_stm32f103xe.s      # Startup file
├── Core/                       # Core source code
│   ├── Src/                    # C source files
│   │   ├── main.c             # Main program
│   │   ├── gpio.c             # GPIO configuration
│   │   ├── i2c.c              # I2C configuration
│   │   ├── usart.c            # USART configuration
│   │   ├── adc.c              # ADC configuration
│   │   └── ...
│   ├── Inc/                    # Header files
│   ├── DHT11/                  # DHT11 driver
│   │   ├── dht11.c
│   │   └── dht11.h
│   └── LCD/                    # LCD driver
│       ├── lcd.c
│       ├── lcd.h
│       ├── tct.c              # LCD image data (720x720 pixel image array)
│       └── ...
├── Drivers/                    # STM32 HAL driver library
│   ├── STM32F1xx_HAL_Driver/
│   └── CMSIS/
└── cmake/                      # CMake auxiliary files
```

### Build Instructions

#### 1. Clone the Repository

```bash
git clone https://github.com/BassttElSevic/Qianrushiqimozuoye.git
cd Qianrushiqimozuoye
```

#### 2. Configure CMake

```bash
cmake -B build -S .
```

#### 3. Build the Project

```bash
cmake --build build
```

#### 4. Flash the Program

Use ST-Link or other programming tools to flash the generated `.bin` or `.hex` file to the STM32F103ZET6 development board.

### Pin Configuration

| Peripheral | Pin | Function |
|------------|-----|----------|
| DHT11 | PG11 | Data line |
| PCF8591 | I2C2 (SCL/SDA) | I2C communication |
| LCD | FSMC | Data and control lines |
| LED0 | PB5 | Status indicator |
| LED1 | PE5 | Status indicator |
| Buzzer | PB8 | Output control |
| USART1 | TX/RX | Serial communication |

### Usage Instructions

1. **Power On**: After powering on, the LCD will display a startup animation and welcome message
2. **Sensor Data Display**: The LCD displays real-time temperature, humidity, and light intensity
3. **Serial Monitoring**: Sensor data can be received through a serial terminal (baud rate according to configuration)
4. **Interrupt Trigger**: Supports switching display modes through external interrupts (buttons, etc.)

### Developer Information

- **Student IDs**: 20252738, 20251643
- **Development Date**: 2025

### License

The STM32 HAL library used in this project follows ST's license terms. Other parts of the project can be used as needed.

---

## 联系方式 / Contact

如有问题或建议，请提交 Issue 或 Pull Request。

For questions or suggestions, please submit an Issue or Pull Request.
