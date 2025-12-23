#include "gpio.h"
#include "timer.h"

// LED连接到GPIOC的13号引脚 (STM32常见配置)
#define LED_PORT    ((GPIO_TypeDef *)GPIOC_BASE)
#define LED_PIN     13

/**
 * @brief  主函数 - LED闪烁示例
 * @retval None
 */
int main(void) {
    // 初始化LED引脚为推挽输出模式, 50MHz
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT_50MHz);
    
    // 主循环
    while (1) {
        // LED点亮
        GPIO_SetBit(LED_PORT, LED_PIN);
        delay_ms(500);  // 延时500ms
        
        // LED熄灭
        GPIO_ResetBit(LED_PORT, LED_PIN);
        delay_ms(500);  // 延时500ms
    }
    
    return 0;
}
