/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "globals.h"
#include "string.h"
#include "dht11.h"
#include "ASCIIdisplay.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line3 interrupt.
  */
void EXTI3_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI3_IRQn 0 */
  HAL_Delay(10);
  exit_inner_loop = 1;
  HAL_Delay(10);
  lcd_clear(WHITE);
  display_quick(10,400,6,46,THANKU);
  display(1,1,26,53,scp);
  delay_ms(20);
  while (1) {
      //lcd_clear(WHITE);
    display(1,1,26,53,scp);
    delay_ms(40);
    display_in_RED(1,1,26,53,scp);
    display_quick(1, 1, 26, 53,scp);
    for (int i = 0; i < 3; i++) {
      display_quick(1, 1, 26, 53,scp_ver2);
      //display_quick(1, 1, 26, 53,scp_ver3);
      display_quick(1, 1, 26, 53,scp_ver4);
      //display_quick(1, 1, 26, 53,scp_ver5);

      display_quick(1, 1, 26, 53,scp_ver7);
      //display_quick(1, 1, 26, 53,scp_ver8);
      display_quick(1, 1, 26, 53,scp_ver9);
      //display_quick(1, 1, 26, 53,scp_ver10);
      display_quick(1, 1, 26, 53,scp_ver11);
      //display_quick(1, 1, 26, 53,scp_ver12);
      display_quick(1, 1, 26, 53,scp_ver13);
    }
    display_quick(1, 1, 26, 53,scp_ver2);
    display_in_RED(1,1,26,53,scp_ver2);
    delay_ms(3000);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    delay_ms(50);
    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    //delay_ms(3);
    //display(1,1,26,53,scp);
    //delay_ms(360);

  }

  // 设置一个标志位而不是直接读取传感器
  // 在主循环中检测这个标志位并执行相应操作
  // 这样可以避免在中断中执行耗时操作

  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY0_Pin);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

  /* USER CODE END EXTI3_IRQn 1 */
}

/**
  * @brief This function handles EXTI line4 interrupt.
  */
void EXTI4_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_IRQn 0 */

  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY1_Pin);
  /* USER CODE BEGIN EXTI4_IRQn 1 */
  HAL_Delay(10);

  exit_inner_loop = 1;
  HAL_Delay(10);

  lcd_clear(BLUE);
  HAL_Delay(10);
  lcd_fill(26, 26, 49, 106, BLACK);
  lcd_fill(23, 23, 43, 100, WHITE);
  //lcd_fill(203,103,506,126,BLACK);
  //lcd_fill(200,100,500,120,GRAY);
  //lcd_fill(183,143,503,153,BLACK);
  //lcd_fill(180,140,500,150,GRAY);
 // lcd_fill(123,173,503,193,BLACK);
  //lcd_fill(120,170,500,190,GRAY);
  //lcd_fill(200,100,500,120,GRAY);
  //lcd_draw_rectangle(23, 23, 43, 100, WHITE);
  Chinese_Show_one(20, 20, 31, 16, 0);
  Chinese_Show_one(20, 40, 32, 16, 0);
  //lcd_fill_circle(265, 500, 200, WHITE);
  lcd_fill_circle(120, 580, 150, YELLOW);
  HAL_Delay(100);
  lcd_fill_circle(265, 500, 200, WHITE);
  //lcd_show_string(45, 100, 200, 18, 24, "STM32F103ZET6", BLUE);
  //lcd_show_string(60, 120, 210, 18, 12, "In labs of silicon and coded light,", BLUE);
  //lcd_show_string(20, 60, 16, 16, 2, "STM32F103ZET6", WHITE);
  HAL_Delay(3500);
  //goto A;

  HAL_Delay(10);
  exit_inner_loop = 1;
  HAL_GPIO_EXTI_IRQHandler(KEY1_Pin);
  /* USER CODE END EXTI4_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
