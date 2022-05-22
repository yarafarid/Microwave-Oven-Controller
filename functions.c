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
#include "EXTERNAL_SWITCH.h"

void Popcorn(void){
	int time = 60;
	LCD_PrintString ("Popcorn");
	delay_inMilli(2000);
	ClearLcd();
	while(1)
		 {
				LCD_PrintString("Press Start");
				delay_inMilli(2000);
			  ClearLcd();
				if (Button_Read('F',0)==0) {
				break ;
		 }
	 }
	count_down(time);
	LCD_PrintString("End of cooking");
	delay_inMilli(2000);
	ClearLcd();
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


















 
