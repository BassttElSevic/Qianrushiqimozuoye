#include "timer.h"
#include "gpio.h"

// LED连接到GPIOC的13号引脚
#define LED_PORT    ((GPIO_TypeDef *)GPIOC_BASE)
#define LED_PIN     13

// 定时器配置
#define TIMER       ((TIM_TypeDef *)TIM2_BASE)

// 全局变量，用于计数
volatile uint32_t timer_count = 0;

/**
 * @brief  定时器中断服务函数
 * @retval None
 */
void TIM2_IRQHandler(void) {
    // 检查更新中断标志
    if (TIMER->SR & TIM_SR_UIF) {
        // 清除中断标志
        TIMER->SR &= ~TIM_SR_UIF;
        
        // 增加计数
        timer_count++;
        
        // 每秒翻转LED (假设定时器配置为1ms中断)
        if (timer_count >= 1000) {
            GPIO_ToggleBit(LED_PORT, LED_PIN);
            timer_count = 0;
        }
    }
}

/**
 * @brief  主函数 - 定时器示例
 * @retval None
 */
int main(void) {
    // 初始化LED引脚
    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUTPUT_50MHz);
    
    // 初始化定时器
    // 预分频器=7200, 周期=10, 产生1ms中断 (假设72MHz时钟)
    Timer_Init(TIMER, 7200, 10);
    
    // 启动定时器
    Timer_Start(TIMER);
    
    // 主循环
    while (1) {
        // 主循环可以处理其他任务
        // LED翻转在中断中处理
    }
    
    return 0;
}
