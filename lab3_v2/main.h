/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#define RED0_Pin GPIO_PIN_1
#define RED0_GPIO_Port GPIOA
#define YELLOW0_Pin GPIO_PIN_2
#define YELLOW0_GPIO_Port GPIOA
#define GREEN0_Pin GPIO_PIN_3
#define GREEN0_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_4
#define RED1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_5
#define YELLOW1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_6
#define GREEN1_GPIO_Port GPIOA
#define BUTTON0_Pin GPIO_PIN_7
#define BUTTON0_GPIO_Port GPIOA
#define SEG0_0_Pin GPIO_PIN_0
#define SEG0_0_GPIO_Port GPIOB
#define SEG0_1_Pin GPIO_PIN_1
#define SEG0_1_GPIO_Port GPIOB
#define SEG0_2_Pin GPIO_PIN_2
#define SEG0_2_GPIO_Port GPIOB
#define ROAD2_1_Pin GPIO_PIN_10
#define ROAD2_1_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_8
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_9
#define BUTTON2_GPIO_Port GPIOA
#define SEG0_3_Pin GPIO_PIN_3
#define SEG0_3_GPIO_Port GPIOB
#define SEG0_4_Pin GPIO_PIN_4
#define SEG0_4_GPIO_Port GPIOB
#define SEG0_5_Pin GPIO_PIN_5
#define SEG0_5_GPIO_Port GPIOB
#define SEG0_6_Pin GPIO_PIN_6
#define SEG0_6_GPIO_Port GPIOB
#define ROAD1_0_Pin GPIO_PIN_7
#define ROAD1_0_GPIO_Port GPIOB
#define ROAD1_1_Pin GPIO_PIN_8
#define ROAD1_1_GPIO_Port GPIOB
#define ROAD2_0_Pin GPIO_PIN_9
#define ROAD2_0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
