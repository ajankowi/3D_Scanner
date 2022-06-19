#include "gpio.h"
#include "main.h"
#include "com.h"


void LCD_go(){

	  LCD_Init();
	  HAL_Delay(50);
	  LCD_Instruction (0b00111000, 0);
	  HAL_Delay(50);
	  LCD_Instruction (0b00001110, 0);
	  HAL_Delay(50);
	  LCD_Instruction (0b00000110, 0);
	  HAL_Delay(50);
	  LCD_Instruction (0b00000001, 0);
	/*
  LCD_Init();
  HAL_Delay(50);

  //LCD_Instruction (0b00110000, 0);
  LCD_Instruction (0b00111000, 0);

  HAL_Delay(50);
  LCD_Instruction (0b00001110, 0);
  HAL_Delay(50);
  LCD_Instruction (0b00000110, 0);
  HAL_Delay(50);
  LCD_Instruction (0b00000001, 0);

  //word("it works!");
  */
}

void Trigger()
{
        HAL_GPIO_WritePin (LCD_E_GPIO_Port, LCD_E_Pin, SET );
        HAL_Delay(1);
        HAL_GPIO_WritePin (LCD_E_GPIO_Port, LCD_E_Pin, RESET );
}

void LCD_Instruction (uint8_t DB, uint8_t RS)
{
        HAL_Delay(2);
        HAL_GPIO_WritePin (LCD_E_GPIO_Port, LCD_E_Pin, SET );

        if (RS)
                HAL_GPIO_WritePin (LCD_RS_GPIO_Port, LCD_RS_Pin, SET );
        else
             	HAL_GPIO_WritePin (LCD_RS_GPIO_Port, LCD_RS_Pin, RESET );

        HAL_GPIO_WritePin (LCD_D7_GPIO_Port, LCD_D7_Pin, DB & (1<<7) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D6_GPIO_Port, LCD_D6_Pin, DB & (1<<6) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D5_GPIO_Port, LCD_D5_Pin, DB & (1<<5) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D4_GPIO_Port, LCD_D4_Pin, DB & (1<<4) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D3_GPIO_Port, LCD_D3_Pin, DB & (1<<3) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D2_GPIO_Port, LCD_D2_Pin, DB & (1<<2) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D1_GPIO_Port, LCD_D1_Pin, DB & (1<<1) ? SET : RESET);
        HAL_GPIO_WritePin (LCD_D0_GPIO_Port, LCD_D0_Pin, DB & (1<<0) ? SET : RESET);
        HAL_Delay(1);
        HAL_GPIO_WritePin (LCD_E_GPIO_Port, LCD_E_Pin, RESET );
}



void LCD_Init()
{
    HAL_Delay (65);
    HAL_GPIO_WritePin (LCD_RS_GPIO_Port, LCD_RS_Pin, RESET );
    HAL_GPIO_WritePin (LCD_D7_GPIO_Port, LCD_D7_Pin, RESET);
    HAL_GPIO_WritePin (LCD_D6_GPIO_Port, LCD_D6_Pin, RESET);
    HAL_GPIO_WritePin (LCD_D5_GPIO_Port, LCD_D5_Pin, SET);
    HAL_GPIO_WritePin (LCD_D4_GPIO_Port, LCD_D4_Pin, SET);
    HAL_GPIO_WritePin (LCD_D3_GPIO_Port, LCD_D3_Pin, RESET );
    HAL_GPIO_WritePin (LCD_D2_GPIO_Port, LCD_D2_Pin, RESET);
    HAL_GPIO_WritePin (LCD_D1_GPIO_Port, LCD_D1_Pin, RESET);
    HAL_GPIO_WritePin (LCD_D0_GPIO_Port, LCD_D0_Pin, RESET);

    Trigger();
    HAL_Delay(7);

    Trigger();
    HAL_Delay(5);

    Trigger();
    HAL_Delay(2);
    LCD_Instruction (0b00111000, 0);

    LCD_Instruction (0b00001110, 0);
    LCD_Instruction (0b00000110, 0);
    LCD_Instruction (0b00000001, 0);
    LCD_Instruction (0b00000110, 0);
	/*
        HAL_Delay (65);
        HAL_GPIO_WritePin (LCD_RS_GPIO_Port, LCD_RS_Pin, RESET );
        HAL_GPIO_WritePin (LCD_D7_GPIO_Port, LCD_D7_Pin, RESET);
        HAL_GPIO_WritePin (LCD_D6_GPIO_Port, LCD_D6_Pin, RESET);
        HAL_GPIO_WritePin (LCD_D5_GPIO_Port, LCD_D5_Pin, SET);
        HAL_GPIO_WritePin (LCD_D4_GPIO_Port, LCD_D4_Pin, SET);
        HAL_GPIO_WritePin (LCD_D3_GPIO_Port, LCD_D3_Pin, RESET );
        HAL_GPIO_WritePin (LCD_D2_GPIO_Port, LCD_D2_Pin, RESET);
        HAL_GPIO_WritePin (LCD_D1_GPIO_Port, LCD_D1_Pin, RESET);
        HAL_GPIO_WritePin (LCD_D0_GPIO_Port, LCD_D0_Pin, RESET);

        Trigger();
        HAL_Delay(7);

        Trigger();
        HAL_Delay(5);

        Trigger();
        HAL_Delay(2);
        //LCD_Instruction (0b00110000, 0);
        LCD_Instruction (0b00111000, 0);


        //LCD_Instruction (0b00110000, 0);
        LCD_Instruction (0b00111000, 0);
        LCD_Instruction (0b00001000, 0);
        LCD_Instruction (0b00000001, 0);
        LCD_Instruction (0b00000110, 0);
*/

}


void letter(char c){
	LCD_Instruction (c, 1);
	HAL_Delay(50);
}

void word(char* text){
	while(*text){
		letter(*text++);
		HAL_Delay(50);
}
}




char alphanum()
{
	int flag = 1;
	//int flaga1 = 1;
	//int flaga2 = 1;
	int32_t tick2 = 0;
	int32_t tick1 = 0;
	int32_t roz = 0;
	uint8_t cout = 1;

	char symbol;

while(flag){
HAL_GPIO_WritePin (KEY_R1_GPIO_Port,KEY_R1_Pin, RESET);
HAL_GPIO_WritePin (KEY_R2_GPIO_Port,KEY_R2_Pin, SET);
HAL_GPIO_WritePin (KEY_R3_GPIO_Port,KEY_R3_Pin, SET);
HAL_GPIO_WritePin (KEY_R4_GPIO_Port,KEY_R4_Pin, SET);


if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0)
	{
	HAL_Delay(200);
	tick1 = HAL_GetTick();
		while(roz<1000){
			tick2 = HAL_GetTick();
			roz = tick2 - tick1;
			if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0){
				cout++;
				HAL_Delay(200);
			}
			if(cout == 1){
				symbol='a';
			}else if(cout == 2)
			{
				symbol='b';
			}else{
				symbol='c';
			}
		}
		flag=0;
	}

if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0)
{
HAL_Delay(200);
tick1 = HAL_GetTick();
	while(roz<1000){
		tick2 = HAL_GetTick();
		roz = tick2 - tick1;
		if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0){
			cout++;
			HAL_Delay(200);
		}
		if(cout == 1){
			symbol='d';
		}else if(cout == 2)
		{
			symbol='e';
		}else{
			symbol='f';
		}
	}
	flag=0;
}



HAL_GPIO_WritePin (KEY_R1_GPIO_Port,KEY_R1_Pin, SET);
HAL_GPIO_WritePin (KEY_R2_GPIO_Port,KEY_R2_Pin, RESET);
HAL_GPIO_WritePin (KEY_R3_GPIO_Port,KEY_R3_Pin, SET);
HAL_GPIO_WritePin (KEY_R4_GPIO_Port,KEY_R4_Pin, SET);

if(HAL_GPIO_ReadPin(KEY_C1_GPIO_Port, KEY_C1_Pin)==0)
{
HAL_Delay(200);
tick1 = HAL_GetTick();
	while(roz<1000){
		tick2 = HAL_GetTick();
		roz = tick2 - tick1;
		if(HAL_GPIO_ReadPin(KEY_C1_GPIO_Port, KEY_C1_Pin)==0){
			cout++;
			HAL_Delay(200);
		}
		if(cout == 1){
			symbol='g';
		}else if(cout == 2)
		{
			symbol='h';
		}else{
			symbol='i';
		}
	}
	flag=0;
}




if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0)
{
HAL_Delay(200);
tick1 = HAL_GetTick();
	while(roz<1000){
		tick2 = HAL_GetTick();
		roz = tick2 - tick1;
		if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0){
			cout++;
			HAL_Delay(200);
		}
		if(cout == 1){
			symbol='j';
		}else if(cout == 2)
		{
			symbol='k';
		}else{
			symbol='l';
		}
	}
	flag=0;
}


if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0)
{
HAL_Delay(200);
tick1 = HAL_GetTick();
	while(roz<1000){
		tick2 = HAL_GetTick();
		roz = tick2 - tick1;
		if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0){
			cout++;
			HAL_Delay(200);
		}
		if(cout == 1){
			symbol='m';
		}else if(cout == 2)
		{
			symbol='n';
		}else{
			symbol='o';
		}
	}
	flag=0;
}



HAL_GPIO_WritePin (KEY_R1_GPIO_Port,KEY_R1_Pin, SET);
HAL_GPIO_WritePin (KEY_R2_GPIO_Port,KEY_R2_Pin, SET);
HAL_GPIO_WritePin (KEY_R3_GPIO_Port,KEY_R3_Pin, RESET);
HAL_GPIO_WritePin (KEY_R4_GPIO_Port,KEY_R4_Pin, SET);

if(HAL_GPIO_ReadPin(KEY_C1_GPIO_Port, KEY_C1_Pin)==0)
{
	HAL_Delay(200);
	tick1 = HAL_GetTick();
		while(roz<1000){
			tick2 = HAL_GetTick();
			roz = tick2 - tick1;
			if(HAL_GPIO_ReadPin(KEY_C1_GPIO_Port, KEY_C1_Pin)==0){
				cout++;
				HAL_Delay(200);
			}
			if(cout == 1){
				symbol='p';
			}else if(cout == 2)
			{
				symbol='q';
			}else if(cout == 3){
				symbol='r';
			}
			else{
				symbol='s';
			}
		}
		flag=0;
	}

if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0)
{
HAL_Delay(200);
tick1 = HAL_GetTick();
	while(roz<1000){
		tick2 = HAL_GetTick();
		roz = tick2 - tick1;
		if(HAL_GPIO_ReadPin(KEY_C2_GPIO_Port, KEY_C2_Pin)==0){
			cout++;
			HAL_Delay(200);
		}
		if(cout == 1){
			symbol='t';
		}else if(cout == 2)
		{
			symbol='u';
		}else{
			symbol='v';
		}
	}
	flag=0;
}

if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0)
{
	HAL_Delay(200);
	tick1 = HAL_GetTick();
		while(roz<1000){
			tick2 = HAL_GetTick();
			roz = tick2 - tick1;
			if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0){
				cout++;
				HAL_Delay(200);
			}
			if(cout == 1){
				symbol='w';
			}else if(cout == 2)
			{
				symbol='x';
			}else if(cout == 3){
				symbol='y';
			}
			else{
				symbol='z';
			}
		}
		flag=0;
	}

HAL_GPIO_WritePin (KEY_R1_GPIO_Port,KEY_R1_Pin, SET);
HAL_GPIO_WritePin (KEY_R2_GPIO_Port,KEY_R2_Pin, SET);
HAL_GPIO_WritePin (KEY_R3_GPIO_Port,KEY_R3_Pin, SET);
HAL_GPIO_WritePin (KEY_R4_GPIO_Port,KEY_R4_Pin, RESET);

if(HAL_GPIO_ReadPin(KEY_C3_GPIO_Port, KEY_C3_Pin)==0)
	{
		symbol='#';		//LCD_Instruction (0b00000001, 0);
		//LCD_Instruction (symbol, 1);
		HAL_Delay(100);
		flag=0;
	}
}//zamkniecie while
return symbol;

}//zamkniecie alphanum



void LCD_clear(){
	LCD_Instruction (0b00000001, 0);
}


