//
// Created by 29113 on 2025/12/23.
//

#ifndef CHUANCHUANKOU_DHT11_H
#define CHUANCHUANKOU_DHT11_H
#include "stm32f1xx_hal.h"
#define DHT11_DQ_GPIO_PORT              GPIOG
#define DHT11_DQ_GPIO_PIN               GPIO_PIN_11
#define DHT11_DQ_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOG_CLK_ENABLE(); }while(0)   /* PG????? */

/******************************************************************************************/

/* DHT11 ??? DQ ??? (???) */
#define DHT11_DQ_OUT(x)                 do{ x ? \
HAL_GPIO_WritePin(DHT11_DQ_GPIO_PORT, DHT11_DQ_GPIO_PIN, GPIO_PIN_SET) : \
HAL_GPIO_WritePin(DHT11_DQ_GPIO_PORT, DHT11_DQ_GPIO_PIN, GPIO_PIN_RESET); \
}while(0)

#define DHT11_DQ_IN                     HAL_GPIO_ReadPin(DHT11_DQ_GPIO_PORT, DHT11_DQ_GPIO_PIN)
uint8_t dht11_init(void);                                   /* ???DHT11????? */
uint8_t dht11_read_data(uint8_t *temp, uint8_t *humi);      /* ????? */
void dht11_timer_delay_us(uint32_t us);


#endif //CHUANCHUANKOU_DHT11_H