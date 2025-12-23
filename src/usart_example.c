#include "usart.h"
#include "gpio.h"
#include "timer.h"

// USART1配置
#define USART_PORT  ((USART_TypeDef *)USART1_BASE)

/**
 * @brief  主函数 - 串口通信示例
 * @retval None
 */
int main(void) {
    char received_char;
    
    // 初始化USART1，波特率115200
    USART_Init(USART_PORT, BAUD_115200);
    
    // 发送欢迎信息
    USART_SendString(USART_PORT, "嵌入式系统串口通信示例\r\n");
    USART_SendString(USART_PORT, "请输入字符，系统将回显:\r\n");
    
    // 主循环
    while (1) {
        // 接收一个字符
        received_char = USART_ReceiveChar(USART_PORT);
        
        // 回显接收到的字符
        USART_SendString(USART_PORT, "收到: ");
        USART_SendChar(USART_PORT, received_char);
        USART_SendString(USART_PORT, "\r\n");
        
        // 如果收到 'q' 或 'Q'，发送退出信息
        if (received_char == 'q' || received_char == 'Q') {
            USART_SendString(USART_PORT, "退出命令已收到\r\n");
        }
    }
    
    return 0;
}
