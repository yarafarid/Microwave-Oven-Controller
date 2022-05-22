#include "tm4c123gh6pm.h"
#include "delaySys.h"
#include "init2.h"
#include "Initialization1.h"
#include "macros.h"
#include "LCDfinalDriver.h"
#include "stdint.h"
#include "ourKeypad.h"




int main(){
		//LCD initialization
  GPIO_Init('A');
	GPIO_Init('B');
	GPIO_PinDirection ('A', 7, 1);// RS
	GPIO_PinDirection ('A', 6, 1);//E
  Port_Direction('B', 0XFF);
	LCD_init();
		//keypad initialization  
		RowKeypad_Init();
	  ColKeypad_Init();

		
			while(1){
				char input = keypad_Read();
				delay_inMilli(350);
				sendChar(input);
				delay_inMilli(350);
			}
			
		}