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
#include "LedsBlink.h"
#include "Buzzer.h"
#include "EXTERNAL_SWITCH.h"


 void BeefOrChicken(unsigned char cook)
 { 
	 int DoorCheck =0;
	 int time;
	 int min_b_c ;
	 int sec_b_c ;
	 int sec_b_c_1 ;
	 int sec_b_c_2 ;
	 int weight;
	 int error_check = 0;
	 if(cook=='B')
	 {
		 LCD_PrintString("Beef weight");
		 delay_inMilli(1000);
		 ClearLcd();
	 }
	 else if (cook=='C')
	 {
		 LCD_PrintString("Chicken weight");
		 delay_inMilli(1000);
		 ClearLcd();
	 }
	 
	 LCD_PrintString("weight : ");
	 weight = keypad_Read() ;
	 sendChar(weight);
	 delay_inMilli(2000);
	 ClearLcd();
	 if((((weight - '0')>=1) && ((weight- '0') <=9))){
					if(cook=='B')
					 {
						 time = (weight - '0') * 30;	 
						 LCD_PrintString("Time : ");
						 delay_inMilli(1000);
						 min_b_c = time / 60;
						 sec_b_c = time%60;
						 sec_b_c_1 = sec_b_c /10;
						 sec_b_c_2 = sec_b_c %10;
						 sendChar(min_b_c + '0');
						 sendChar(':');
						 sendChar(sec_b_c_1+ '0');
						 sendChar(sec_b_c_2+ '0');	
						 delay_inMilli(1000);				
						 ClearLcd();
					 }
					else if (cook=='C')
					 {
						 time = (weight - '0') * 12 ;
						 LCD_PrintString("Time : ");
						 delay_inMilli(1000);
						 min_b_c = time / 60;
						 sec_b_c = time%60;
						 sec_b_c_1 = sec_b_c /10;
						 sec_b_c_2 = sec_b_c %10;
						 sendChar(min_b_c + '0');
						 sendChar(':');
						 sendChar(sec_b_c_1+ '0');
						 sendChar(sec_b_c_2+ '0');
						 delay_inMilli(1000);
						 ClearLcd();
					 }			 
			 }						
			else 
				{
				 LCD_PrintString("Error");
				 delay_inMilli(2000);
				 ClearLcd();
				 if(cook == 'B'){BeefOrChicken('B');}
				 else{BeefOrChicken('C');}
				 error_check++;
				}
	 if(error_check == 0){
		 while(!(Button_Read('F',0)==0))    										
		 {
				LCD_PrintString("Press Start");
				delay_inMilli(2000);
				ClearLcd();
		 }
	 }
	 
	 while (Door_Status() == 1){           
				LCD_PrintString ("Door is Open");
				delay_inMilli(1000);
					ClearLcd();
			 DoorCheck +=1;
		 }	
		 if(DoorCheck !=0 ){
				LCD_PrintString("Door is closed");
				delay_inMilli(1000);
				ClearLcd(); 
		 }

	 count_down(time);
	 LCD_PrintString("End of cooking");
	 delay_inMilli(2000);
	 ClearLcd();
	 }
 }
