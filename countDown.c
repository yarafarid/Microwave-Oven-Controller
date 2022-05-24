#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "LCDfinalDriver.h"
#include "stdio.h"
#include "keypad.h"
#include "Button.h"
#include "LedBlinking.h"
#include "LedBlinking.h"
#include "LedBlinking_withbuzzer.h"
#include "EXTERNAL_SWITCH.h"
#include "Initialization1.h"
#include "init2.h"
#include "delaySys.h"

void count_down(int time)
 {	
	 int sec = time%60;
	 int min = time/60;
      	 int Time_At_Pause  = 0;
	 int min1 ;
	 int min2 ;
	 int sec1 ;
	 int sec2 ;
	 unsigned char pause_flag = 0;
         int i = 0 ;
	 int Door_check = 0;
	 int check = 0;
	 for(i = time ; i>=0; i--)
	 {		char min1 = min/10;
			char min2 = min%10;
			char sec1 = sec/10;
			char sec2 = sec%10;
			LCD_PrintString("counting : ");
			  if(min >= 0){
				sendChar(min1 + '0');
				sendChar(min2 + '0');
			   }
				sendChar(':');
	  		  if(sec >= 0){
				sendChar(sec1 + '0');
				sendChar(sec2 + '0');
			   }
						 if((Button_Read('F',4)==0 && (pause_flag == 0))
						 {
							 ClearLcd();
							 Time_At_Pause = i+1 ;                                                        
							 pause_flag = 1 ;
							 LCD_PrintString("cooking paused");
							 delay_inMilli(2000);
							 ClearLcd();
							 LCD_PrintString("Time : ");
							 sendChar(min1 + '0');
							 sendChar(min2 + '0');
							 sendChar(':');
							 sendChar(sec1 + '0');
							 sendChar((++sec2) + '0');
							 
							 while(!(Button_Read('F',4)== 0 && (pause_flag ==1)) 
												
								{
									LedBlinking();
									if (Button_Read('F',0)== 0 )
									{ 
									ClearLcd();
									delay_inMilli(500);
									count_down(Time_At_Pause);
									check++;
									break ;			
								         }		
								}
							       break;
					                }
							 if((Door_Status()== 1))
							 {
								 ClearLcd();
								 Time_At_Pause = i+1 ;
								 pause_flag = 1 ;
								 LCD_PrintString("Door is open");
								 delay_inMilli(1000);
								 ClearLcd();
								 LCD_PrintString("Time : ");
								 sendChar(min1 + '0');
								 sendChar(min2 + '0');
								 sendChar(':');
								 sendChar(sec1 + '0');
								 sendChar((++sec2) + '0');
							while((Door_Status()== 1))             
							{	
								LedBlinking();
							}
							ClearLcd();
							LCD_PrintString("Door is closed");
							delay_inMilli(1000);
							ClearLcd();
							delay_inMilli(500);
							count_down(Time_At_Pause) ;
							check++;
							break;
							}
		       if(sec >= 0){
			  sec-- ;
			}
			if(sec == -1){
			   min--;
			   sec =59;
			}
			LedOn();
		        delay_inMilli(1000);
		        ClearLcd();
 }
	if (Button_Read('F',4)== 0 && (pause_flag ==1)) { // sw1 -> second time 		
	    ClearLcd();
	    LCD_PrintString("cooking stopped");	
	    delay_inMilli(2000);
	    ClearLcd();
	}
	
if(check == 0){
			LedOff();
			delay_inMilli(1000);
			LedBlinking_withbuzzer();	
	}
  }

