#include "gpio.h"

/**
 * @brief  初始化GPIO引脚
 * @param  GPIOx: GPIO端口指针
 * @param  pin: 引脚编号 (0-15)
 * @param  mode: GPIO模式
 * @retval None
 */
void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode) {
    if (pin < 8) {
        // 配置CRL寄存器 (引脚0-7)
        GPIOx->CRL &= ~(0x0F << (pin * 4));
        GPIOx->CRL |= (mode << (pin * 4));
    } else {
        // 配置CRH寄存器 (引脚8-15)
        GPIOx->CRH &= ~(0x0F << ((pin - 8) * 4));
        GPIOx->CRH |= (mode << ((pin - 8) * 4));
    }
}

/**
 * @brief  设置GPIO引脚为高电平
 * @param  GPIOx: GPIO端口指针
 * @param  pin: 引脚编号 (0-15)
 * @retval None
 */
void GPIO_SetBit(GPIO_TypeDef *GPIOx, uint8_t pin) {
    GPIOx->BSRR = (1 << pin);
}

/**
 * @brief  设置GPIO引脚为低电平
 * @param  GPIOx: GPIO端口指针
 * @param  pin: 引脚编号 (0-15)
 * @retval None
 */
void GPIO_ResetBit(GPIO_TypeDef *GPIOx, uint8_t pin) {
    GPIOx->BRR = (1 << pin);
}

/**
 * @brief  读取GPIO引脚电平
 * @param  GPIOx: GPIO端口指针
 * @param  pin: 引脚编号 (0-15)
 * @retval 引脚电平 (0或1)
 */
uint8_t GPIO_ReadBit(GPIO_TypeDef *GPIOx, uint8_t pin) {
    return (GPIOx->IDR & (1 << pin)) ? 1 : 0;
}

/**
 * @brief  翻转GPIO引脚电平
 * @param  GPIOx: GPIO端口指针
 * @param  pin: 引脚编号 (0-15)
 * @retval None
 */
void GPIO_ToggleBit(GPIO_TypeDef *GPIOx, uint8_t pin) {
    GPIOx->ODR ^= (1 << pin);
}
