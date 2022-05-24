#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "LCDfinalDriver.h"
#include "stdio.h"
#include "ourKeypad.h"
#include "Button.h"
#include "init2.h"
#include "Initialization1.h"
#include "delaySys.h"
#include "countDown.h"
#include "Buzzer.h"
#include "A_func.h"
#include "BandC_func.h"
#include "D_fun.h"


int main(){
		char input ;
		GPIO_Init('A');
		GPIO_Init('B');
		GPIO_Init('D');
		GPIO_Init ('F');
		GPIO_PinDirection ('A', 7, 1);// RS
		GPIO_PinDirection ('A', 6, 1);//E
		Port_Direction('B', 0XFF);
		LCD_init();
		Buzzer_Init();
		// keypad initialization  
	  ColKeypad_Init();
		RowKeypad_Init();
		Button_Init_PUll_UP('F' , 0);
		Button_Init_PUll_UP('F' , 4);
		D_Init();
		
	while(1){
		LCD_PrintString("Enter char : ") ;
		input = keypad_Read();
		sendChar(input);
		delay_inMilli(1000);
		ClearLcd();
		switch(input)
		{
			case 'A' : { Popcorn(); }
			break;
			case 'B' :
			case 'C' : { BeefOrChicken(input); }
			break;
			case 'D' : { D_pressed();}
			break;
		}
		
	
	}
}