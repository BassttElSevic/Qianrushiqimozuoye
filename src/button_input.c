#include "gpio.h"
#include "timer.h"

// 按钮连接到GPIOA的0号引脚
#define BUTTON_PORT ((GPIO_TypeDef *)GPIOA_BASE)
#define BUTTON_PIN  0

// LED连接到GPIOC的13号引脚
#define LED_PORT    ((GPIO_TypeDef *)GPIOC_BASE)
#define LED_PIN     13

/**
 * @brief  主函数 - 按钮控制LED示例
 * @retval None
 */
int main(void) {
    uint8_t last_state = 0;
    uint8_t current_state = 0;
    
    // 初始化按钮引脚为输入模式
    GPIO_Init(BUTTON_PORT, BUTTON_PIN, GPIO_MODE_INPUT);
    
    // 初始化LED引脚为推挽输出模式
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT_50MHz);
    
    // LED初始状态为熄灭
    GPIO_ResetBit(LED_PORT, LED_PIN);
    
    // 主循环
    while (1) {
        // 读取按钮状态
        current_state = GPIO_ReadBit(BUTTON_PORT, BUTTON_PIN);
        
        // 检测按钮按下事件（上升沿）
        if (current_state == 1 && last_state == 0) {
            // 翻转LED状态
            GPIO_ToggleBit(LED_PORT, LED_PIN);
            
            // 简单的消抖延时
            delay_ms(20);
        }
        
        // 更新上次状态
        last_state = current_state;
        
        // 短暂延时，避免CPU占用过高
        delay_ms(10);
    }
    
    return 0;
}
