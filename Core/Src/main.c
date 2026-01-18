/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "globals.h"
#include "tct.h"
#include "string.h"
#include "dht11.h"
//#include "stdlib.h"
//#include "lcdfont.h"
//#include "adc.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint8_t exit_inner_loop = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t PCF8591_Read_AIN1(I2C_HandleTypeDef *hi2c) {
  uint8_t cmd = 0x41;
  uint8_t adc_data = 0;
  HAL_I2C_Master_Transmit(hi2c, 0x90, &cmd, 1, 100);
  HAL_I2C_Master_Receive(hi2c, 0x90, &adc_data, 1, 100);
  return adc_data;
}

uint8_t PCF8591_Read_AIN2(I2C_HandleTypeDef *hi2c) {
  uint8_t cmd2 = 0x42;
  uint8_t adc_data2 = 0;
  HAL_I2C_Master_Transmit(hi2c, 0x90, &cmd2, 1, 100);
  HAL_I2C_Master_Receive(hi2c, 0x90, &adc_data2, 1, 100);
  return adc_data2;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  MX_USART2_UART_Init();
  MX_ADC3_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim1); // Start TIM1 for DHT11 delays
    delay_init(72);
    uint8_t humidity;
  uint8_t MyTemP;
  dht11_init();
  uint8_t temperature;
  char god[64];
  uint16_t t = 0;

    led_init();
    lcd_init();
    //adc_temperature_init();
  //short temp;
    //lcd_show_string(30, 50, 200, 16, 16, "hello world");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
  HAL_Delay(70);

    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
  HAL_Delay(170);

    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(70);

    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);HAL_Delay(170);

    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
  HAL_Delay(800);
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);





    Chinese_Show_one(95,20, 20, 16, 0);
    Chinese_Show_one(110,20, 21, 16, 0);
    Chinese_Show_one(125,20, 22, 16, 0);
    Chinese_Show_one(140,20, 23, 16, 0);
    Chinese_Show_one(155,20, 24, 16, 0);
    Chinese_Show_one(170,20, 25, 16, 0);
    Chinese_Show_one(185,20, 26, 16, 0);
    Chinese_Show_one(200,20, 27, 16, 0);
    Chinese_Show_one(215,20, 28, 16, 0);

    delay_ms(10);
     lcd_show_string(60, 50, 200, 18, 16, "@@...@@ ######### @@...@@",  BLACK);
    delay_ms(20);
     lcd_show_string(60, 70, 200, 18, 16, "#@@...@@ ####### @@...@@#", BLACK);//1   25个字符
    delay_ms(30);
     lcd_show_string(60, 90, 200, 18, 16, "# @@....@ ##### @....@@ #", BLACK);//2
    delay_ms(40);
    lcd_show_string(60, 110, 200, 18, 16, "## @.....@ ### @.....@ ##", BLACK);//3
    delay_ms(50);
    lcd_show_string(60, 130, 200, 18, 16, "### @@....@ # @....@@ ###", BLACK);//4
    delay_ms(60);
    lcd_show_string(60, 150, 200, 18, 16, "######@.... @ ....@######", BLACK);//5
    delay_ms(70);
    lcd_show_string(60, 170, 200, 18, 16, "######@.... @ ....@######", BLACK);//6
    delay_ms(80);
    lcd_show_string(60, 190, 200, 18, 16, "### @@....@ # @....@@ ###", BLACK);//7
    delay_ms(100);
    lcd_show_string(60, 210, 200, 18, 16, "## @.....@ ### @.....@ ##", BLACK);//8
    delay_ms(100);
    lcd_show_string(60, 230, 200, 18, 16, "# @.....@ ##### @.....@ #", BLACK);//9
    delay_ms(80);
    lcd_show_string(60, 250, 200, 18, 16, "#@@...@@ ####### @@...@@#", BLACK);//10
    delay_ms(70);
    lcd_show_string(60, 270, 200, 18, 16, "@@...@@ ######### @@...@@", BLACK);//11
    HAL_Delay(60);
  //show_picture(60, 50, 120, 240,(unsigned short *)gImage_HEAD240240);
    //show_picture(60, 50, 60, 60,A);
  HAL_Delay(100);
//how_picture(60, 50,60,360,gImage_tct)
// show_picture(01, 80, 360, 180,(unsigned short *)gImage_tct);
//Display_picture(60, 50, 240, 240,(unsigned short *)gImage_tct);
  HAL_Delay(100);

    lcd_show_string(60, 290, 200, 18, 16, "-------------------------", BLACK);
    delay_ms(10);
    lcd_show_string(60, 290, 200, 18, 16, "-H-----------------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HE----------------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HEL---------------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELL--------------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-------------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-W-----------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WO----------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WOR---------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORL--------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-------------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-H-----------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HE----------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HEL---------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELL--------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-------", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-W-----", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WO----", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WOR---", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORL--", BLACK);
    delay_ms(5);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORLD-", BLACK);
//ahdfiawhfjkahnjka
    Chinese_Show_one(60, 310, 8, 16, 0);
    Chinese_Show_one(240, 310, 9, 16, 0);
    delay_ms(5);
     Chinese_Show_one(80, 310, 0, 16, 0);
    delay_ms(5);
    Chinese_Show_one(100, 310, 5, 16, 0);
    delay_ms(5);
    Chinese_Show_one(120, 310, 2, 16, 0);
    delay_ms(5);
    Chinese_Show_one(140, 310, 7, 16, 0);
    delay_ms(5);
    Chinese_Show_one(160, 310, 0, 16, 0);
    delay_ms(5);
    Chinese_Show_one(180, 310, 5, 16, 0);
    delay_ms(5);
    Chinese_Show_one(200, 310, 2, 16, 0);
    delay_ms(5);
    Chinese_Show_one(220, 310, 7, 16, 0);
    delay_ms(5);

    //Chinese_Show_one(240, 310, 9, 16, 0);
///
//
///
    Chinese_Show_one(60, 330, 16, 16, 0);
    delay_ms(3);
    Chinese_Show_one(80, 330, 17, 16, 0);
    delay_ms(3);
    Chinese_Show_one(100, 330, 18, 16, 0);
    delay_ms(3);
    Chinese_Show_one(120, 330, 19, 16, 0);
    delay_ms(3);

    Chinese_Show_one(140, 330, 13, 16, 0);
    delay_ms(3);
    Chinese_Show_one(155, 330, 14, 16, 0);
    delay_ms(3);
    Chinese_Show_one(170, 330, 15, 16, 0);
    delay_ms(3);

    Chinese_Show_one(200, 330, 10, 16, 0);
    delay_ms(3);
    Chinese_Show_one(215, 330, 11, 16, 0);
    delay_ms(3);
    Chinese_Show_one(230, 330, 12, 16, 0);
    delay_ms(3);

    Chinese_Show_one(60, 350, 29, 16, 0);
    delay_ms(3);
    Chinese_Show_one(100, 350, 30, 16, 0);
    delay_ms(3);
    Chinese_Show_one(120, 350, 19, 16, 0);
    delay_ms(3);

    lcd_show_string(140, 350, 200, 18, 16, "--------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "2-------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "20------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "202-----", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "2025----", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "20252---", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "202527--", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "2025273-", BLACK);
    delay_ms(14);
    lcd_show_string(140, 350, 200, 18, 16, "20252738", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "--------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "2-------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "20------", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "202-----", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "2025----", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "20251---", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "202516--", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "2025164-", BLACK);
    delay_ms(14);
    lcd_show_string(140, 370, 200, 18, 16, "20251643", BLACK);
    delay_ms(14);

    HAL_Delay(1500);
  lcd_show_string(60, 50, 200, 18, 16, "                         ",  BLACK);

  lcd_show_string(60, 70, 200, 18, 16, "                         ", BLACK);//1

  lcd_show_string(60, 250, 200, 18, 16, "                         ", BLACK);//10

  lcd_show_string(60, 270, 200, 18, 16, "                         ", BLACK);//11

  show_picture(01, 80, 360, 180,(unsigned short *)gImage_tct);

  if (exit_inner_loop == 1) {
    HAL_Delay(10);
    goto A;
  }
    lcd_show_string(60, 290, 200, 18, 16, "-------------------------", BLACK);
  if (exit_inner_loop == 1) {
    HAL_Delay(10);
    goto A;
  }
    HAL_Delay(500);
  if (exit_inner_loop == 1) {
    goto A;
  }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORLD-", BLACK);
  if (exit_inner_loop == 1) {
    HAL_Delay(10);
    goto A;
  }
  HAL_Delay(1000);
  if (exit_inner_loop == 1) {
    HAL_Delay(10);
    goto A;
  }
    lcd_show_string(60, 290, 200, 18, 16, "------------A------------", BLACK);//为什么中断结束后会停在这里？
    HAL_Delay(500);
  if (exit_inner_loop == 1) {
    goto A;
  }
  HAL_Delay(10);
  while (1)
  {
    if (exit_inner_loop == 1) {
      HAL_Delay(20);
      goto A;
      //HAL_Delay(10);
    }




    //exit_inner_loop = 0; // 重置标志
      //if (exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(20);
      goto A;
      //HAL_Delay(10);
    }
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(20);
      goto A;
      //HAL_Delay(10);
    }

    lcd_show_string(60, 290, 200, 18, 16, "-------------------------", BLACK);
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      goto A;
    }
    // if(exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-H-----------------------", BLACK);
    //if(exit_inner_loop) continue;
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    delay_ms(10);
    lcd_show_string(60, 290, 200, 18, 16, "-HE----------------------", BLACK);
    //if(exit_inner_loop) continue;
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    delay_ms(10);
    lcd_show_string(60, 290, 200, 18, 16, "-HEL---------------------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELL--------------------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-------------------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-W-----------------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WO----------------", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WOR---------------", BLACK);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORL--------------", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-------------", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-H-----------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HE----------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HEL---------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELL--------", BLACK);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-------", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-W-----", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WO----", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WOR---", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORL--", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(10);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORLD-", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(1000);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-------------------------", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(500);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    lcd_show_string(60, 290, 200, 18, 16, "-HELLO-WORLD-HELLO-WORLD-", BLACK);
    //if(exit_inner_loop) continue;
    delay_ms(1000);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }
    HAL_Delay(10);
    lcd_show_string(60, 290, 200, 18, 16, "-------------------------", BLACK);
    //if(exit_inner_loop) continue;
    HAL_Delay(500);
    if (exit_inner_loop == 1) {
      HAL_Delay(10);
      goto A;
    }



    //lcd_show_string(30, 50, 200, 16, 20, "hello world", GREEN);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  A:
  lcd_clear(BLUE);
  HAL_Delay(1000);
    lcd_draw_circle(170, 240, 30,WHITE);
    lcd_draw_circle(120, 300,70,WHITE);
    lcd_draw_circle(300, 120, 100,WHITE);
    lcd_draw_circle(70, 470, 120,WHITE);
while(1){
  // 检查是否需要读取DHT11传感器
  dht11_read_data(&MyTemP, &humidity);
  int len = sprintf(god, "HUMINOW:%d", humidity);
  HAL_UART_Transmit(&huart1, (uint8_t *)god, len, 100);
  lcd_show_string(40, 120, 200, 18, 32, god, BLUE);

  HAL_UART_Transmit(&huart1, (uint8_t *)god, strlen(god), 100);

  uint16_t adc_val = PCF8591_Read_AIN1(&hi2c2);
  adc_val = 1000 - adc_val;
  delay_ms(2);
  while (adc_val > 700) {
    delay_ms(9);
    adc_val = 900 - adc_val;
    delay_ms(9);
  }







  HAL_Delay(2);
  //adc_val = 1000 - adc_val;
  char send_buf[32];
  HAL_Delay(4);
  if (adc_val > 900) {
    HAL_Delay(3);
    adc_val = 900 - adc_val;
    HAL_Delay(2);
  }

   HAL_Delay(4);

  LED0_TOGGLE();

  char buffer[32];
  HAL_Delay(9);
  if (adc_val > 700) {
    HAL_Delay(9);
    adc_val = 900 - adc_val;
    HAL_Delay(9);
    while (adc_val > 700) {
      HAL_Delay(9);
      adc_val = 900 - adc_val;
      HAL_Delay(9);
    }

    sprintf(buffer, "TEMP:%d", adc_val);
    lcd_show_string(40, 40, 200, 18, 32, buffer, BLUE);
     sprintf(send_buf,"TEMP Value:%d\r\n",adc_val);
      HAL_UART_Transmit(&huart1, (uint8_t *)send_buf, strlen(send_buf), 100);
  }
  else {
  sprintf(buffer, "TEMP:%d", adc_val);
  lcd_show_string(40, 40, 200, 18, 32, buffer, BLUE);
     sprintf(send_buf,"TEMP:%d\r\n",adc_val);
      HAL_UART_Transmit(&huart1, (uint8_t *)send_buf, strlen(send_buf), 100);
  }
   HAL_Delay(9);

  uint8_t adc_val2 = PCF8591_Read_AIN2(&hi2c2);
  char buffer2[32];
  //char send_buf2[32];
  adc_val2 = 600 - adc_val2;
  while (adc_val2 > 400) {
    delay_ms(2);
    adc_val2 = 600 - adc_val2;
    delay_ms(2);
  }
  sprintf(buffer2, "LIGHT:%d", adc_val2);
  HAL_UART_Transmit(&huart1, (uint8_t *)buffer2, strlen(buffer2), 100);
  HAL_Delay(2);
  lcd_show_string(40, 80, 200, 18, 32, buffer2, BLUE);
  HAL_Delay(2);

  //dht11_read_data(&temperature, &humidity);
  //int len = sprintf(god, "TEMP:%d,Humi:%d%%\r\n", temperature,humidity);
  //sprintf(god, "TEMP:%d,Humi:%d%%\r\n", temperature,humidity);
  //HAL_UART_Transmit(&huart2, (uint8_t *)god, len, 100);
  //lcd_show_string(40, 120, 200, 18, 32, god, BLUE);
  //temp = adc_get_temperature();


}    //5
  //lcd_clear(BLUE);


  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {


  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
