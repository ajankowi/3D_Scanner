#include "gpio.h"
#include "tim.h"
#include "main.h"
#include "StepMotor.h"


volatile uint8_t i = 0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(htim->Instance == TIM6){
		i++;
	}
}


void SM_reset(){

	HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_RESET);
}


void half_step_motor_left(uint32_t angle, uint8_t number){

	HAL_TIM_Base_Start_IT(&htim6);

	uint32_t ac = 1;

	if(number == 1){
		for (; ac <= angle;){
			if(i == 0){
				HAL_GPIO_WritePin(StepM_2_1_GPIO_Port, StepM_2_1_Pin, GPIO_PIN_SET);
			}
			if(i == 1){
				HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 2){
				HAL_GPIO_WritePin(StepM_3_1_GPIO_Port, StepM_3_1_Pin, GPIO_PIN_SET);
			}
			if(i == 3){
				HAL_GPIO_WritePin(StepM_2_1_GPIO_Port, StepM_2_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 4){
				HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_SET);
			}
			if(i == 5){
				HAL_GPIO_WritePin(StepM_3_1_GPIO_Port, StepM_3_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 6){
				HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_SET);
			}
			if(i == 7){
				HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_RESET);
			}
			if(i >= 8){
				i = 0;
				ac++;
			}
		}
		//HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim6);
	}
	if(number == 2){
			for (; ac <= angle;){
				if(i == 0){
					HAL_GPIO_WritePin(StepM_2_2_GPIO_Port, StepM_2_2_Pin, GPIO_PIN_SET);
				}
				if(i == 1){
					HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_RESET);
				}
				if(i == 2){
					HAL_GPIO_WritePin(StepM_3_2_GPIO_Port, StepM_3_2_Pin, GPIO_PIN_SET);
				}
				if(i == 3){
					HAL_GPIO_WritePin(StepM_2_2_GPIO_Port, StepM_2_2_Pin, GPIO_PIN_RESET);
				}
				if(i == 4){
					HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_SET);
				}
				if(i == 5){
					HAL_GPIO_WritePin(StepM_3_2_GPIO_Port, StepM_3_2_Pin, GPIO_PIN_RESET);
				}
				if(i == 6){
					HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_SET);
				}
				if(i == 7){
					HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_RESET);
				}
				if(i >= 8){
					i = 0;
					ac++;
				}
			}
			//HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_RESET);
			HAL_TIM_Base_Stop_IT(&htim6);
		}

}



void half_step_motor_right(uint32_t angle, uint8_t number){

	HAL_TIM_Base_Start_IT(&htim6);

	uint32_t ac = 1;

	if(number == 1){
		for (; ac <= angle;){

			if(i == 0){
				HAL_GPIO_WritePin(StepM_3_1_GPIO_Port, StepM_3_1_Pin, GPIO_PIN_SET);
			}
			if(i == 1){
				HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 2){
				HAL_GPIO_WritePin(StepM_2_1_GPIO_Port, StepM_2_1_Pin, GPIO_PIN_SET);
			}
			if(i == 3){
				HAL_GPIO_WritePin(StepM_3_1_GPIO_Port, StepM_3_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 4){
				HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_SET);
			}
			if(i == 5){
				HAL_GPIO_WritePin(StepM_2_1_GPIO_Port, StepM_2_1_Pin, GPIO_PIN_RESET);
			}
			if(i == 6){
				HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_SET);
			}
			if(i == 7){
				HAL_GPIO_WritePin(StepM_1_1_GPIO_Port, StepM_1_1_Pin, GPIO_PIN_RESET);
			}
			if(i >= 8){
				i = 0;
				ac++;
			}
		}
		//HAL_GPIO_WritePin(StepM_4_1_GPIO_Port, StepM_4_1_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim6);
	}

	if(number == 2){
		for (; ac <= angle;){

			if(i == 0){
				HAL_GPIO_WritePin(StepM_3_2_GPIO_Port, StepM_3_2_Pin, GPIO_PIN_SET);
			}
			if(i == 1){
				HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_RESET);
			}
			if(i == 2){
				HAL_GPIO_WritePin(StepM_2_2_GPIO_Port, StepM_2_2_Pin, GPIO_PIN_SET);
			}
			if(i == 3){
				HAL_GPIO_WritePin(StepM_3_2_GPIO_Port, StepM_3_2_Pin, GPIO_PIN_RESET);
			}
			if(i == 4){
				HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_SET);
			}
			if(i == 5){
				HAL_GPIO_WritePin(StepM_2_2_GPIO_Port, StepM_2_2_Pin, GPIO_PIN_RESET);
			}
			if(i == 6){
				HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_SET);
			}
			if(i == 7){
				HAL_GPIO_WritePin(StepM_1_2_GPIO_Port, StepM_1_2_Pin, GPIO_PIN_RESET);
			}
			if(i >= 8){
				i = 0;
				ac++;
			}
		}
		//HAL_GPIO_WritePin(StepM_4_2_GPIO_Port, StepM_4_2_Pin, GPIO_PIN_RESET);
		HAL_TIM_Base_Stop_IT(&htim6);
	}

}
