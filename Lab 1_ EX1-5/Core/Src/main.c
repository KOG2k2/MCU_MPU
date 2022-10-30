/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RED_WEST_ON() HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, GPIO_PIN_SET)
#define RED_WEST_OFF() HAL_GPIO_WritePin(RED_WEST_GPIO_Port, RED_WEST_Pin, GPIO_PIN_RESET)

#define YELLOW_WEST_ON() HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, GPIO_PIN_SET)
#define YELLOW_WEST_OFF() HAL_GPIO_WritePin(YELLOW_WEST_GPIO_Port, YELLOW_WEST_Pin, GPIO_PIN_RESET)

#define GREEN_WEST_ON() HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, GPIO_PIN_SET)
#define GREEN_WEST_OFF() HAL_GPIO_WritePin(GREEN_WEST_GPIO_Port, GREEN_WEST_Pin, GPIO_PIN_RESET)

#define RED_NORTH_ON() HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, GPIO_PIN_SET)
#define RED_NORTH_OFF() HAL_GPIO_WritePin(RED_NORTH_GPIO_Port, RED_NORTH_Pin, GPIO_PIN_RESET)

#define YELLOW_NORTH_ON() HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, GPIO_PIN_SET)
#define YELLOW_NORTH_OFF() HAL_GPIO_WritePin(YELLOW_NORTH_GPIO_Port, YELLOW_NORTH_Pin, GPIO_PIN_RESET)

#define GREEN_NORTH_ON() HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, GPIO_PIN_SET)
#define GREEN_NORTH_OFF() HAL_GPIO_WritePin(GREEN_NORTH_GPIO_Port, GREEN_NORTH_Pin, GPIO_PIN_RESET)

#define DELAY 1000

#define RED_COUNTER 5
#define YELLOW_COUNTER 2
#define GREEN_COUNTER 3
#define GENERAL_COUNTER 2

#define RESET_TIME 0

#define ON 1
#define OFF 0

#define RUN_COUNT 10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int counter = 0;
int timer_counter = GENERAL_COUNTER;
enum state {RED_WEST_ON, RED_YELLOW_WEST, GREEN_WEST_ON, YELLOW_WEST_ON};
enum state currstate = RED_WEST_ON;

int RED_WEST_count = RED_COUNTER;
int YELLOW_WEST_count = YELLOW_COUNTER;
int GREEN_WEST_count = GREEN_COUNTER;

int RED_NORTH_count = RED_COUNTER;
int YELLOW_NORTH_count = YELLOW_COUNTER;
int GREEN_NORTH_count = GREEN_COUNTER;

int RED_WEST_stat = ON;
int YELLOW_WEST_stat = OFF;
int GREEN_WEST_stat = OFF;

int RED_NORTH_stat = OFF;
int YELLOW_NORTH_stat = OFF;
int GREEN_NORTH_stat = ON;

int LED_buffer[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int num){
	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, ((LED_buffer[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, ((LED_buffer[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, ((LED_buffer[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, ((LED_buffer[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, ((LED_buffer[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, ((LED_buffer[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, ((LED_buffer[num] >> 6) & 0x01));
}

void display7SEG2(int num){
	HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, ((LED_buffer[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, ((LED_buffer[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, ((LED_buffer[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, ((LED_buffer[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, ((LED_buffer[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, ((LED_buffer[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, ((LED_buffer[num] >> 6) & 0x01));
}

void check7SEG(){
	if(counter >= RUN_COUNT) counter = RESET_TIME;
	display7SEG(counter++);
}

void LED_SWITCHING(){
	if(RED_WEST_stat == ON && timer_counter == RESET_TIME){
		  timer_counter = GENERAL_COUNTER;
		  RED_WEST_stat = OFF;
		  YELLOW_WEST_stat = ON;
	}

	  if(YELLOW_WEST_stat == ON && timer_counter == RESET_TIME){
		  timer_counter = GENERAL_COUNTER;
		  RED_WEST_stat = ON;
		  YELLOW_WEST_stat = OFF;
	  }

	  if(RED_WEST_stat == ON){
		  RED_WEST_ON();
		  timer_counter--;
	  }
	  if(RED_WEST_stat == OFF) RED_WEST_OFF();

	  if(YELLOW_WEST_stat == ON){
		  YELLOW_WEST_ON();
		  timer_counter--;
	  }
	  if(YELLOW_WEST_stat == OFF) YELLOW_WEST_OFF();
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /*------------------EX1----------
		LED_SWITCHING();
	  */

	  /*------------------EX4----------*/
	   check7SEG();

	  /*------------------EX2-3-5----------*/
	  /*if(RED_WEST_stat == ON && RED_WEST_count == RESET_TIME){
		  RED_WEST_count = RED_COUNTER;
		  RED_WEST_stat = OFF;
		  YELLOW_WEST_stat = OFF;
		  GREEN_WEST_stat = ON;
	  }

	  if(GREEN_WEST_stat == ON && GREEN_WEST_count == RESET_TIME){
		  GREEN_WEST_count = GREEN_COUNTER;
		  RED_WEST_stat = OFF;
		  YELLOW_WEST_stat = ON;
		  GREEN_WEST_stat = OFF;
	  }

	  if(YELLOW_WEST_stat == ON && YELLOW_WEST_count == RESET_TIME){
		  YELLOW_WEST_count = YELLOW_COUNTER;
		  RED_WEST_stat = ON;
		  YELLOW_WEST_stat = OFF;
		  GREEN_WEST_stat = OFF;
	  }

	  if(RED_WEST_stat == ON){
		  RED_WEST_ON();
		  display7SEG(RED_WEST_count);
		  RED_WEST_count--;
	  }
	  if(RED_WEST_stat == OFF) RED_WEST_OFF();

	  if(YELLOW_WEST_stat == ON){
		  YELLOW_WEST_ON();
		  display7SEG(YELLOW_WEST_count);
		  YELLOW_WEST_count--;
	  }
	  if(RED_WEST_stat == OFF) YELLOW_WEST_OFF();

	  if(GREEN_WEST_stat == ON){
		  GREEN_WEST_ON();
		  display7SEG(GREEN_WEST_count);
		  GREEN_WEST_count--;
	  }
	  if(GREEN_WEST_stat == OFF) GREEN_WEST_OFF();

	  if(RED_NORTH_stat == ON && RED_NORTH_count == RESET_TIME){
		  RED_NORTH_count = RED_COUNTER;
		  RED_NORTH_stat = OFF;
		  YELLOW_NORTH_stat = OFF;
		  GREEN_NORTH_stat = ON;
	  }

	  if(GREEN_NORTH_stat == ON && GREEN_NORTH_count == RESET_TIME){
		  GREEN_NORTH_count = GREEN_COUNTER;
		  RED_NORTH_stat = OFF;
		  YELLOW_NORTH_stat = ON;
		  GREEN_NORTH_stat = OFF;
	  }

	  if(YELLOW_NORTH_stat == ON && YELLOW_NORTH_count == RESET_TIME){
		  YELLOW_NORTH_count = YELLOW_COUNTER;
		  RED_NORTH_stat = ON;
		  YELLOW_NORTH_stat = OFF;
		  GREEN_NORTH_stat = OFF;
	  }

	  if(RED_NORTH_stat == ON){
		  RED_NORTH_ON();
		  display7SEG2(RED_NORTH_count);
		  RED_NORTH_count--;
	  }
	  if(RED_NORTH_stat == OFF) RED_NORTH_OFF();

	  if(YELLOW_NORTH_stat == ON){
		  YELLOW_NORTH_ON();
		  display7SEG2(YELLOW_NORTH_count);
		  YELLOW_NORTH_count--;
	  }
	  if(YELLOW_NORTH_stat == OFF) YELLOW_NORTH_OFF();

	  if(GREEN_NORTH_stat == ON){
		  GREEN_NORTH_ON();
		  display7SEG2(GREEN_NORTH_count);
		  GREEN_NORTH_count--;
	  }
	  if(GREEN_NORTH_stat == OFF) GREEN_NORTH_OFF();*/

	  HAL_Delay(DELAY);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_WEST_Pin|YELLOW_WEST_Pin|GREEN_WEST_Pin|RED_NORTH_Pin
                          |YELLOW_NORTH_Pin|GREEN_NORTH_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED_WEST_Pin YELLOW_WEST_Pin GREEN_WEST_Pin RED_NORTH_Pin
                           YELLOW_NORTH_Pin GREEN_NORTH_Pin */
  GPIO_InitStruct.Pin = RED_WEST_Pin|YELLOW_WEST_Pin|GREEN_WEST_Pin|RED_NORTH_Pin
                          |YELLOW_NORTH_Pin|GREEN_NORTH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a1_Pin b1_Pin c1_Pin d2_Pin
                           e2_Pin f2_Pin g2_Pin d1_Pin
                           e1_Pin f1_Pin g1_Pin a2_Pin
                           b2_Pin c2_Pin */
  GPIO_InitStruct.Pin = a1_Pin|b1_Pin|c1_Pin|d2_Pin
                          |e2_Pin|f2_Pin|g2_Pin|d1_Pin
                          |e1_Pin|f1_Pin|g1_Pin|a2_Pin
                          |b2_Pin|c2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
