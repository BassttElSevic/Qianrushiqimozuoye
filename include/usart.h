#ifndef USART_H
#define USART_H

#include <stdint.h>

// USART寄存器基地址
#define USART1_BASE  0x40013800
#define USART2_BASE  0x40004400
#define USART3_BASE  0x40004800

// USART寄存器结构
typedef struct {
    volatile uint32_t SR;       // 状态寄存器
    volatile uint32_t DR;       // 数据寄存器
    volatile uint32_t BRR;      // 波特率寄存器
    volatile uint32_t CR1;      // 控制寄存器1
    volatile uint32_t CR2;      // 控制寄存器2
    volatile uint32_t CR3;      // 控制寄存器3
    volatile uint32_t GTPR;     // 保护时间和预分频寄存器
} USART_TypeDef;

// 波特率定义
#define BAUD_9600    9600
#define BAUD_115200  115200

// USART控制寄存器位定义
#define USART_CR1_UE    0x2000  // USART使能
#define USART_CR1_TE    0x0008  // 发送使能
#define USART_CR1_RE    0x0004  // 接收使能

// USART状态寄存器位定义
#define USART_SR_TXE    0x0080  // 发送数据寄存器空
#define USART_SR_RXNE   0x0020  // 接收数据寄存器非空

// 函数声明
void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate);
void USART_SendChar(USART_TypeDef *USARTx, char ch);
void USART_SendString(USART_TypeDef *USARTx, const char *str);
char USART_ReceiveChar(USART_TypeDef *USARTx);

#endif // USART_H
