#include "timer.h"

/**
 * @brief  初始化定时器
 * @param  TIMx: 定时器指针
 * @param  prescaler: 预分频值
 * @param  period: 自动重装载值
 * @retval None
 */
void Timer_Init(TIM_TypeDef *TIMx, uint16_t prescaler, uint16_t period) {
    // 设置预分频器
    TIMx->PSC = prescaler - 1;
    
    // 设置自动重装载值
    TIMx->ARR = period - 1;
    
    // 使能更新中断
    TIMx->DIER |= 0x01;  // UIE=1
    
    // 生成更新事件，重新初始化计数器
    TIMx->EGR = 0x01;    // UG=1
}

/**
 * @brief  启动定时器
 * @param  TIMx: 定时器指针
 * @retval None
 */
void Timer_Start(TIM_TypeDef *TIMx) {
    TIMx->CR1 |= 0x01;   // CEN=1
}

/**
 * @brief  停止定时器
 * @param  TIMx: 定时器指针
 * @retval None
 */
void Timer_Stop(TIM_TypeDef *TIMx) {
    TIMx->CR1 &= ~0x01;  // CEN=0
}

/**
 * @brief  毫秒级延时函数
 * @param  ms: 延时时间(毫秒)
 * @retval None
 */
void delay_ms(uint32_t ms) {
    // 简单的延时实现，实际应用中应该使用定时器或系统滴答定时器
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 8000; j++);
    }
}

/**
 * @brief  微秒级延时函数
 * @param  us: 延时时间(微秒)
 * @retval None
 */
void delay_us(uint32_t us) {
    // 简单的延时实现，实际应用中应该使用定时器
    volatile uint32_t i, j;
    for (i = 0; i < us; i++) {
        for (j = 0; j < 8; j++);
    }
}
