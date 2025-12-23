#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

// 定时器寄存器基地址
#define TIM2_BASE   0x40000000
#define TIM3_BASE   0x40000400
#define TIM4_BASE   0x40000800

// 定时器寄存器结构
typedef struct {
    volatile uint32_t CR1;      // 控制寄存器1
    volatile uint32_t CR2;      // 控制寄存器2
    volatile uint32_t SMCR;     // 从模式控制寄存器
    volatile uint32_t DIER;     // DMA/中断使能寄存器
    volatile uint32_t SR;       // 状态寄存器
    volatile uint32_t EGR;      // 事件生成寄存器
    volatile uint32_t CCMR1;    // 捕获/比较模式寄存器1
    volatile uint32_t CCMR2;    // 捕获/比较模式寄存器2
    volatile uint32_t CCER;     // 捕获/比较使能寄存器
    volatile uint32_t CNT;      // 计数器
    volatile uint32_t PSC;      // 预分频器
    volatile uint32_t ARR;      // 自动重装载寄存器
} TIM_TypeDef;

// 函数声明
void Timer_Init(TIM_TypeDef *TIMx, uint16_t prescaler, uint16_t period);
void Timer_Start(TIM_TypeDef *TIMx);
void Timer_Stop(TIM_TypeDef *TIMx);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

// 定时器控制寄存器位定义
#define TIM_CR1_CEN     0x0001  // 计数器使能
#define TIM_DIER_UIE    0x0001  // 更新中断使能
#define TIM_EGR_UG      0x0001  // 更新事件生成
#define TIM_SR_UIF      0x0001  // 更新中断标志

// 延时函数参数（与CPU时钟相关）
#define DELAY_MS_LOOP_COUNT  8000  // 1ms延时循环次数 (72MHz CPU)
#define DELAY_US_LOOP_COUNT  8     // 1us延时循环次数 (72MHz CPU)

#endif // TIMER_H
