#include "usart.h"

/**
 * @brief  初始化USART
 * @param  USARTx: USART端口指针
 * @param  baudrate: 波特率
 * @retval None
 */
void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate) {
    // 设置波特率 (假设系统时钟为72MHz, APB2时钟为72MHz)
    uint32_t apbclock = 72000000;
    uint32_t integerdivider = (25 * apbclock) / (4 * baudrate);
    uint32_t tmpreg = (integerdivider / 100) << 4;
    tmpreg |= ((integerdivider % 100) * 16 + 50) / 100;
    USARTx->BRR = tmpreg;
    
    // 使能USART, 发送和接收
    USARTx->CR1 = 0x200C;  // UE=1, TE=1, RE=1
}

/**
 * @brief  发送一个字符
 * @param  USARTx: USART端口指针
 * @param  ch: 要发送的字符
 * @retval None
 */
void USART_SendChar(USART_TypeDef *USARTx, char ch) {
    // 等待发送数据寄存器为空
    while (!(USARTx->SR & 0x80));  // TXE标志
    USARTx->DR = ch;
}

/**
 * @brief  发送字符串
 * @param  USARTx: USART端口指针
 * @param  str: 要发送的字符串
 * @retval None
 */
void USART_SendString(USART_TypeDef *USARTx, const char *str) {
    while (*str) {
        USART_SendChar(USARTx, *str++);
    }
}

/**
 * @brief  接收一个字符
 * @param  USARTx: USART端口指针
 * @retval 接收到的字符
 */
char USART_ReceiveChar(USART_TypeDef *USARTx) {
    // 等待接收数据寄存器非空
    while (!(USARTx->SR & 0x20));  // RXNE标志
    return (char)USARTx->DR;
}
