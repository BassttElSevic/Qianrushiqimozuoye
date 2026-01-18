//
// Created by 29113 on 2025/12/23.
//

#include "dht11.h"
extern TIM_HandleTypeDef htim1;


void dht11_timer_delay_us(uint32_t us)
{
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}//等待达到指定微秒数


static void dht11_reset(void)
{
    DHT11_DQ_OUT(0);  //拉高
    dht11_timer_delay_us(20000); //拉低至少18ms
    DHT11_DQ_OUT(1);
    dht11_timer_delay_us(30); //主机拉高20-40us
}


uint8_t dht11_check(void)
{
    uint8_t rval = 0;
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (DHT11_DQ_IN && __HAL_TIM_GET_COUNTER(&htim1) < 100); //DHT11会拉低约80us
    if (__HAL_TIM_GET_COUNTER(&htim1) >= 100)
    {
        rval = 1;
    }
    else
    {
        __HAL_TIM_SET_COUNTER(&htim1, 0);
        while (!DHT11_DQ_IN && __HAL_TIM_GET_COUNTER(&htim1) < 100); //拉低后又会拉高
        if (__HAL_TIM_GET_COUNTER(&htim1) >= 100)
        {
            rval = 1;
        }
    }
    return rval;
}

uint8_t dht11_read_bit(void)
{
    uint8_t data;
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (DHT11_DQ_IN && __HAL_TIM_GET_COUNTER(&htim1) < 100);//等待变为低电平

    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (!DHT11_DQ_IN && __HAL_TIM_GET_COUNTER(&htim1) < 100);//等待变为高电平

    dht11_timer_delay_us(40); //等待40us

    if (DHT11_DQ_IN)
    {
        data = 1;
    }
    else
    {
        data = 0;
    }

    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while(DHT11_DQ_IN && __HAL_TIM_GET_COUNTER(&htim1) < 100);

    return data;
}

static uint8_t dht11_read_byte(void)
{
    uint8_t i, data = 0;

    for (i = 0; i < 8; i++)         //循环读取8位数据
    {
        data <<= 1;
        data |= dht11_read_bit();
    }

    return data;
}

uint8_t dht11_read_data(uint8_t *temp, uint8_t *humi)
{
    uint8_t buf[5];
    uint8_t i;
    dht11_reset();

    if (dht11_check() == 0)
    {
        for (i = 0; i < 5; i++) //读取40位数据
        {
            buf[i] = dht11_read_byte();
        }

        if ((buf[0] + buf[1] + buf[2] + buf[3]) == buf[4])
        {
            *humi = buf[0];
            *temp = buf[2];
        }
    }
    else
    {
        return 1;
    }

    return 0;
}


uint8_t dht11_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;

    DHT11_DQ_GPIO_CLK_ENABLE();

    gpio_init_struct.Pin = DHT11_DQ_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_OD;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(DHT11_DQ_GPIO_PORT, &gpio_init_struct);

    dht11_reset();
    return dht11_check();
}
