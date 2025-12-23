# 嵌入式系统基础作业 Makefile

# 编译器和工具链设置
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# 目标芯片 (STM32F103C8T6为例)
MCU = -mcpu=cortex-m3 -mthumb

# 编译选项
CFLAGS = $(MCU) -Wall -O2 -g
CFLAGS += -I./include

# 链接选项
LDFLAGS = $(MCU) -specs=nosys.specs

# 源文件目录
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# 库源文件
LIB_SRCS = $(SRC_DIR)/gpio.c $(SRC_DIR)/usart.c $(SRC_DIR)/timer.c

# 示例程序目标
EXAMPLES = led_blink button_input usart_example timer_example

# 默认目标
all: $(EXAMPLES)

# 编译LED闪烁示例
led_blink: $(LIB_SRCS) $(SRC_DIR)/led_blink.c
	@echo "编译 LED闪烁示例..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BUILD_DIR)/$@.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.bin
	$(OBJCOPY) -O ihex $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.hex
	$(SIZE) $(BUILD_DIR)/$@.elf

# 编译按钮输入示例
button_input: $(LIB_SRCS) $(SRC_DIR)/button_input.c
	@echo "编译 按钮输入示例..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BUILD_DIR)/$@.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.bin
	$(OBJCOPY) -O ihex $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.hex
	$(SIZE) $(BUILD_DIR)/$@.elf

# 编译串口通信示例
usart_example: $(LIB_SRCS) $(SRC_DIR)/usart_example.c
	@echo "编译 串口通信示例..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BUILD_DIR)/$@.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.bin
	$(OBJCOPY) -O ihex $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.hex
	$(SIZE) $(BUILD_DIR)/$@.elf

# 编译定时器示例
timer_example: $(LIB_SRCS) $(SRC_DIR)/timer_example.c
	@echo "编译 定时器示例..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(BUILD_DIR)/$@.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.bin
	$(OBJCOPY) -O ihex $(BUILD_DIR)/$@.elf $(BUILD_DIR)/$@.hex
	$(SIZE) $(BUILD_DIR)/$@.elf

# 清理编译文件
clean:
	@echo "清理编译文件..."
	rm -rf $(BUILD_DIR)

# 显示帮助信息
help:
	@echo "嵌入式系统基础作业 - 可用命令:"
	@echo "  make              - 编译所有示例程序"
	@echo "  make led_blink    - 编译LED闪烁示例"
	@echo "  make button_input - 编译按钮输入示例"
	@echo "  make usart_example- 编译串口通信示例"
	@echo "  make timer_example- 编译定时器示例"
	@echo "  make clean        - 清理所有编译文件"
	@echo "  make help         - 显示此帮助信息"

.PHONY: all clean help
