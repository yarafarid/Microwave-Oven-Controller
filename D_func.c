#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "init2.h"
#include "Initialization1.h"
#include "Button.h"
#include "LCDfinalDriver.h"
#include "ourKeypad.h"
#include "delaySys.h"
#include <stdio.h>
#include "countDown.h"
#include "Buzzer.h"
#include "EXTERNAL_SWITCH.h"

unsigned char valid(int Time , int T2) {
		
   if (Time>1800){
	   
	   LCD_PrintString("Exceed 30 mins") ;
	   delay_inMilli(2000);
	   return 0;
   }
	
   else if (T2 > 5){
	   
	   LCD_PrintString("Exceed 59 secs") ;
	   delay_inMilli(2000);
	   return 0;
   }
   else return 1 ;
}

void D_Init() {
	Button_Init_PUll_UP('F' , 0) ;
	Button_Init_PUll_UP('F' , 4) ;
}

void D_pressed()
{
	int ClearCheck = 0;
	int DoorCheck =0;
	int t1 =0; 
	int t2 =0;
	int t3 =0;
	int t4 =0;
	int tvalue =0;
	int total_time_in_seconds;
	unsigned char cnt = 0 ;	
	int time = 0 , input;
  	LCD_PrintString("Cooking Time ?") ;
	delay_inMilli(1000);
	ClearLcd() ;
	LCD_PrintString("Time :") ;
	delay_inMilli (50);
	sendChar (t4 + '0') ;
	delay_inMilli (50);
	sendChar (t3 + '0') ;
	delay_inMilli (50);
	sendChar (':') ;
	delay_inMilli (50);
	sendChar (t2 + '0') ;
	delay_inMilli (50);
	sendChar (t1 + '0') ;
	delay_inMilli (1000);
	ClearLcd() ;
	while (1){
		if (Button_Read('F',0)==0) {
			break ;
		}
		if (Button_Read('F',4) == 0){ 
			ClearLcd() ;	
			D_pressed() ;
			ClearCheck ++;
		}
		if (ClearCheck == 1){
			break;
		}
		if (cnt == 4){
			total_time_in_seconds =( (((t4-'0')*10 +(t3-'0'))*60) + ((t2-'0')*10 +(t1-'0')) );
			ClearLcd() ;
			LCD_PrintString("Time :") ;
			sendChar(t4);
			sendChar(t3);
			sendChar(':');
			sendChar(t2);
			sendChar(t1);
			delay_inMilli (2000);
			ClearLcd() ;
			LCD_PrintString("start or clear") ;
			delay_inMilli (2000);
			continue;
		}
		if(cnt==0){
			LCD_PrintString("Time : ") ;
			delay_inMilli (50);
			sendChar (t4 + '0') ;
			delay_inMilli (50);
			sendChar (t3 + '0') ;
			delay_inMilli (50);
			sendChar (':') ;
			delay_inMilli (50);
			sendChar (t2 + '0') ;
			delay_inMilli (50);
			tvalue = keypad_Read() ;
			t1 = tvalue;
			delay_inMilli (50);
			sendChar (t1) ;
			delay_inMilli (1000);
			ClearLcd() ;
		}
		else if(cnt==1){
			LCD_PrintString("Time : ") ;
			delay_inMilli (50);
			sendChar (t4 + '0') ;
			delay_inMilli (50);
			sendChar (t3 + '0') ;
			delay_inMilli (50);
			sendChar (':') ;
			delay_inMilli (50);
			t2= t1;
			sendChar (t2) ;
			delay_inMilli (50);
			tvalue = keypad_Read() ;
			t1 = tvalue;
			delay_inMilli (50);
			sendChar (t1) ;
			delay_inMilli (1000);
			ClearLcd() ;
		}
		else if(cnt==2){
			LCD_PrintString("Time : ") ;
			delay_inMilli (50);
			sendChar (t4 + '0') ;
			delay_inMilli (50);
			t3 = t2;
			sendChar (t3) ;
			delay_inMilli (50);
			sendChar (':') ;
			delay_inMilli (50);
			t2 = t1;
			sendChar (t2) ;
			delay_inMilli (50);
			tvalue = keypad_Read() ;
			t1 = tvalue;
			delay_inMilli (50);
			sendChar (t1) ;
			delay_inMilli (1000);
			ClearLcd() ;
		}
		else if(cnt==3){
			LCD_PrintString("Time : ") ;
			delay_inMilli (50);
			t4 = t3;
			sendChar (t4) ;
			delay_inMilli (50);
			t3 = t2;
			sendChar (t3) ;
			delay_inMilli (50);
			sendChar (':') ;
			delay_inMilli (50);
			t2 = t1;
			sendChar (t2) ;
			delay_inMilli (50);
			tvalue = keypad_Read() ;
			t1 = tvalue;
			delay_inMilli (50);
			sendChar (t1) ;
			delay_inMilli (1000);
		}
	cnt ++ ;
	}
	if(ClearCheck ==0){
		ClearLcd() ;
		if (valid(total_time_in_seconds , (t2-'0'))==0){
			D_pressed() ;
		}
		else  {
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
			count_down( total_time_in_seconds );
			LCD_PrintString("End of cooking");
			delay_inMilli(2000);
			ClearLcd();
		}
	}
}
