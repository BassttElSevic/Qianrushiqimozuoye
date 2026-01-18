/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.c
  * @brief   This file provides code for the configuration
  *          of the ADC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "adc.h"

/* USER CODE BEGIN 0 */
ADC_HandleTypeDef g_adc_handle;
/* USER CODE END 0 */

ADC_HandleTypeDef hadc3;

/* ADC3 init function */
void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(adcHandle->Instance==ADC3)
  {
  /* USER CODE BEGIN ADC3_MspInit 0 */

  /* USER CODE END ADC3_MspInit 0 */
    /* ADC3 clock enable */
    __HAL_RCC_ADC3_CLK_ENABLE();

    __HAL_RCC_GPIOF_CLK_ENABLE();
    /**ADC3 GPIO Configuration
    PF8     ------> ADC3_IN6
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /* USER CODE BEGIN ADC3_MspInit 1 */

  /* USER CODE END ADC3_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC3)
  {
  /* USER CODE BEGIN ADC3_MspDeInit 0 */

  /* USER CODE END ADC3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC3_CLK_DISABLE();

    /**ADC3 GPIO Configuration
    PF8     ------> ADC3_IN6
    */
    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_8);

  /* USER CODE BEGIN ADC3_MspDeInit 1 */

  /* USER CODE END ADC3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

ADC_TypeDef * ADC_ADCX;

void adc_init(void)
{
  g_adc_handle.Instance = ADC_ADCX;                        /* Ñ¡ÔñÄÄ¸öADC */
  g_adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;       /* Êý¾Ý¶ÔÆë·½Ê½£ºÓÒ¶ÔÆë */
  g_adc_handle.Init.ScanConvMode = ADC_SCAN_DISABLE;       /* ·ÇÉ¨ÃèÄ£Ê½£¬½öÓÃµ½Ò»¸öÍ¨µÀ */
  g_adc_handle.Init.ContinuousConvMode = DISABLE;          /* ¹Ø±ÕÁ¬Ðø×ª»»Ä£Ê½ */
  g_adc_handle.Init.NbrOfConversion = 1;                   /* ¸³Öµ·¶Î§ÊÇ1~16£¬±¾ÊµÑéÓÃµ½1¸ö¹æÔòÍ¨µÀÐòÁÐ */
  g_adc_handle.Init.DiscontinuousConvMode = DISABLE;       /* ½ûÖ¹¹æÔòÍ¨µÀ×é¼ä¶ÏÄ£Ê½ */
  g_adc_handle.Init.NbrOfDiscConversion = 0;               /* ÅäÖÃ¼ä¶ÏÄ£Ê½µÄ¹æÔòÍ¨µÀ¸öÊý£¬½ûÖ¹¹æÔòÍ¨µÀ×é¼ä¶ÏÄ£Ê½ºó£¬´Ë²ÎÊýºöÂÔ */
  g_adc_handle.Init.ExternalTrigConv = ADC_SOFTWARE_START; /* ´¥·¢×ª»»·½Ê½£ºÈí¼þ´¥·¢ */
  HAL_ADC_Init(&g_adc_handle);                             /* ³õÊ¼»¯ */

  HAL_ADCEx_Calibration_Start(&g_adc_handle);              /* Ð£×¼ADC */
}

void adc_temperature_init(void)
{
  adc_init(); /* ÏÈ³õÊ¼»¯ADC */
  SET_BIT(g_adc_handle.Instance->CR2, ADC_CR2_TSVREFE);  /* TSVREFE = 1, ÆôÓÃÄÚ²¿ÎÂ¶È´«¸ÐÆ÷ºÍVrefint */
}

void adc_channel_set(ADC_HandleTypeDef *adc_handle, uint32_t ch, uint32_t rank, uint32_t stime)
{
  ADC_ChannelConfTypeDef adc_ch_conf;

  adc_ch_conf.Channel = ch;                            /* Í¨µÀ */
  adc_ch_conf.Rank = rank;                             /* ÐòÁÐ */
  adc_ch_conf.SamplingTime = stime;                    /* ²ÉÑùÊ±¼ä */
  HAL_ADC_ConfigChannel(adc_handle, &adc_ch_conf);     /* Í¨µÀÅäÖÃ */
}

uint32_t adc_get_result(uint32_t ch)
{
  adc_channel_set(&g_adc_handle , ch, ADC_REGULAR_RANK_1, ADC_SAMPLETIME_239CYCLES_5);    /* ÉèÖÃÍ¨µÀ£¬ÐòÁÐºÍ²ÉÑùÊ±¼ä */

  HAL_ADC_Start(&g_adc_handle);                            /* ¿ªÆôADC */
  HAL_ADC_PollForConversion(&g_adc_handle, 10);            /* ÂÖÑ¯×ª»» */
  return (uint16_t)HAL_ADC_GetValue(&g_adc_handle);        /* ·µ»Ø×î½üÒ»´ÎADC1¹æÔò×éµÄ×ª»»½á¹û */
}

uint32_t adc_get_result_average(uint32_t ch, uint8_t times)
{
  uint32_t temp_val = 0;
  uint8_t t;

  for (t = 0; t < times; t++)     /* »ñÈ¡times´ÎÊý¾Ý */
  {
    temp_val += adc_get_result(ch);
    delay_ms(5);
  }

  return temp_val / times;        /* ·µ»ØÆ½¾ùÖµ */
}

uint32_t ADC_TEMPSENSOR_CHX;

short adc_get_temperature(void)
{
  uint32_t adcx;
  short result;
  double temperature;

  adcx = adc_get_result_average(ADC_TEMPSENSOR_CHX, 20);  /* ¶ÁÈ¡ÄÚ²¿ÎÂ¶È´«¸ÐÆ÷Í¨µÀ,10´ÎÈ¡Æ½¾ù */
  temperature = (float)adcx * (3.3 / 4096);               /* ×ª»¯ÎªµçÑ¹Öµ */
  temperature = (1.43 - temperature) / 0.0043 + 25;       /* ¼ÆËãÎÂ¶È */
  result = temperature *= 100;    /* À©´ó100±¶. */
  return result;

}


/* USER CODE END 1 */
