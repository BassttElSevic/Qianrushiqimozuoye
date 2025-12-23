#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// GPIO端口定义
#define GPIOA_BASE  0x40010800
#define GPIOB_BASE  0x40010C00
#define GPIOC_BASE  0x40011000

// GPIO寄存器结构
typedef struct {
    volatile uint32_t CRL;      // 端口配置低寄存器
    volatile uint32_t CRH;      // 端口配置高寄存器
    volatile uint32_t IDR;      // 端口输入数据寄存器
    volatile uint32_t ODR;      // 端口输出数据寄存器
    volatile uint32_t BSRR;     // 端口位设置/清除寄存器
    volatile uint32_t BRR;      // 端口位清除寄存器
    volatile uint32_t LCKR;     // 端口配置锁定寄存器
} GPIO_TypeDef;

// GPIO模式定义
#define GPIO_MODE_INPUT         0x00
#define GPIO_MODE_OUTPUT_10MHz  0x01
#define GPIO_MODE_OUTPUT_2MHz   0x02
#define GPIO_MODE_OUTPUT_50MHz  0x03

// 函数声明
void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode);
void GPIO_SetBit(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ResetBit(GPIO_TypeDef *GPIOx, uint8_t pin);
uint8_t GPIO_ReadBit(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_ToggleBit(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif // GPIO_H
