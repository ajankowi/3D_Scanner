#ifndef INC_COM_H_
#define INC_COM_H_



void Trigger();

void LCD_Instruction (uint8_t DB, uint8_t RS);

void LCD_Init();

void letter(char c);

void word(char* text);

char alphanum();

void LCD_go();

void LCD_clear();






#endif /* INC_COM_H_ */
