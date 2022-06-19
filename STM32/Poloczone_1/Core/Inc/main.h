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
#include "stm32l4xx_hal.h"

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
#define TIM6_PRESCALER 7999
#define TIM6_PERIOD 9
#define LCD_RS_Pin GPIO_PIN_13
#define LCD_RS_GPIO_Port GPIOC
#define StepM_1_1_Pin GPIO_PIN_0
#define StepM_1_1_GPIO_Port GPIOA
#define StepM_2_1_Pin GPIO_PIN_1
#define StepM_2_1_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define StepM_3_1_Pin GPIO_PIN_4
#define StepM_3_1_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LCD_D5_Pin GPIO_PIN_5
#define LCD_D5_GPIO_Port GPIOC
#define StepM_4_1_Pin GPIO_PIN_0
#define StepM_4_1_GPIO_Port GPIOB
#define KEY_R4_Pin GPIO_PIN_1
#define KEY_R4_GPIO_Port GPIOB
#define KEY_C1_Pin GPIO_PIN_2
#define KEY_C1_GPIO_Port GPIOB
#define KEY_C2_Pin GPIO_PIN_11
#define KEY_C2_GPIO_Port GPIOB
#define KEY_R1_Pin GPIO_PIN_13
#define KEY_R1_GPIO_Port GPIOB
#define KEY_R2_Pin GPIO_PIN_14
#define KEY_R2_GPIO_Port GPIOB
#define KEY_R3_Pin GPIO_PIN_15
#define KEY_R3_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_6
#define LCD_D6_GPIO_Port GPIOC
#define SD_CD_Pin GPIO_PIN_7
#define SD_CD_GPIO_Port GPIOC
#define LCD_D7_Pin GPIO_PIN_8
#define LCD_D7_GPIO_Port GPIOC
#define LCD_D3_Pin GPIO_PIN_8
#define LCD_D3_GPIO_Port GPIOA
#define LCD_D4_Pin GPIO_PIN_9
#define LCD_D4_GPIO_Port GPIOA
#define LCD_D0_Pin GPIO_PIN_10
#define LCD_D0_GPIO_Port GPIOA
#define KEY_C3_Pin GPIO_PIN_11
#define KEY_C3_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define StepM_4_2_Pin GPIO_PIN_15
#define StepM_4_2_GPIO_Port GPIOA
#define StepM_3_2_Pin GPIO_PIN_10
#define StepM_3_2_GPIO_Port GPIOC
#define StepM_1_2_Pin GPIO_PIN_11
#define StepM_1_2_GPIO_Port GPIOC
#define StepM_2_2_Pin GPIO_PIN_12
#define StepM_2_2_GPIO_Port GPIOC
#define LCD_E_Pin GPIO_PIN_3
#define LCD_E_GPIO_Port GPIOB
#define LCD_D2_Pin GPIO_PIN_4
#define LCD_D2_GPIO_Port GPIOB
#define LCD_D1_Pin GPIO_PIN_5
#define LCD_D1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
