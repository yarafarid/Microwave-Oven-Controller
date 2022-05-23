#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "stdio.h"
#include "init2.h"
#include "Initialization1.h"
#include "delaySys.h"
#include "LCDfinalDriver.h"
#include "macros.h"

/* this function was made to make sure that the LCD is working properly */

//	==============for testing the LCD================
int main(){
	//LCD initialization
        GPIO_Init('A');
	GPIO_Init('B');
	GPIO_PinDirection ('A', 7, 1);// RS
	GPIO_PinDirection ('A', 6, 1);//E
        Port_Direction('B', 0XFF);
LCD_init();
while(1)
{
readyToPrint();

sendChar('T');
delay_inMilli(1);
sendChar('E');
delay_inMilli(1);
sendChar('S');
delay_inMilli(1);
sendChar('T');
delay_inMilli(500);
}
}
	
