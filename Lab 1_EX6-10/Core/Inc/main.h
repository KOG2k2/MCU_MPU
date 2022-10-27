/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED1_Pin GPIO_PIN_2
#define RED1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_3
#define RED2_GPIO_Port GPIOA
#define RED3_Pin GPIO_PIN_4
#define RED3_GPIO_Port GPIOA
#define RED4_Pin GPIO_PIN_5
#define RED4_GPIO_Port GPIOA
#define RED5_Pin GPIO_PIN_6
#define RED5_GPIO_Port GPIOA
#define RED6_Pin GPIO_PIN_7
#define RED6_GPIO_Port GPIOA
#define RED7_Pin GPIO_PIN_8
#define RED7_GPIO_Port GPIOA
#define RED8_Pin GPIO_PIN_9
#define RED8_GPIO_Port GPIOA
#define RED9_Pin GPIO_PIN_10
#define RED9_GPIO_Port GPIOA
#define RED10_Pin GPIO_PIN_11
#define RED10_GPIO_Port GPIOA
#define RED11_Pin GPIO_PIN_12
#define RED11_GPIO_Port GPIOA
#define RED12_Pin GPIO_PIN_13
#define RED12_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
