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

void count_down(int totalTime)
 {	
	 int sec = totalTime%60;
	 int min = totalTime/60;
       	int totalTimePause = 0;
	 int SW1Pressed = 0;
	 int minAtPause = 0;
	 int sec_At_Pause  = 0;
	
	 unsigned char pause_flag = 0;
	 
         int i = sec ;
	 char t_m[100] , t_s[100];
	for(;min >= 0 ; min--){
	 for( ; i>0; i--)
	 {
		 LCD_PrintString("counting : ");
						 if((Button_Read('F',4)==0 && (pause_flag == 0) )|| (Door_Status()== 1))//sw1 pressed for the first time)
						 {
							 ClearLcd();
							 sec_At_Pause = i+1;
                                                         minAtPause = min;
							 totalTimePause = (minAtPause*60) + (sec_At_Pause);
							 pause_flag = 1 ;
							 LCD_PrintString("first step");
							 delay_inMilli(2000);
							 ClearLcd();
							 sprintf(t_m,"%d",minAtPause);
							 LCD_PrintString(t_m);
					
							 sendChar(':');
							 sprintf(t_s,"%d",i+1);
							 LCD_PrintString(t_s);
							 
							 
							 while(!(Button_Read('F',4)== 0 && (pause_flag ==1)) || (Door_Status()== 1)) 
												
								{
									LedBlinking();
									if (Button_Read('F',0)== 0 ){ 
									ClearLcd();
									delay_inMilli(1000);
									count_down(totalTimePause) ;
										break ;			
								         }
									else if(!(Button_Read('F',0)== 0 ) && (Door_Status()== 1) ){
									ClearLcd();
									delay_inMilli(1000);
									 count_down(totalTimePause) ;
										
								}
							
					                         }
							SW1Pressed +=1;					
							break; 
						 }
			
			                        LedOn();
	                                       sprintf(t_m,"%d",min);
						LCD_PrintString(t_m);
						 sendChar(':');
						 sprintf(t_s,"%d",i);
						 LCD_PrintString(t_s);
			
		                              delay_inMilli(1000);
		                              ClearLcd();
 }
		if(i == 0){
		sec = 59 ;
		i = sec ;	
		}
	else if (SW1Pressed == 1){
	 break;
	 }
	}
	 
	 
 
	if (Button_Read('F',4)== 0 && (pause_flag ==1)) { // sw1 -> second time 
			         
				
	    ClearLcd();
	    LCD_PrintString("cooking stopped");		            
	}
	
	LedOff();
	delay_inMilli(1000);
        LedBlinking_withbuzzer();	
		
  }
