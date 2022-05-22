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
	 unsigned char cook_time,pause_flag = 0;
	 unsigned char Time_At_Pause  = 0;
         int i  ;
	 char t[100];
	 for(i = time ; i>0; i--)
	 {
		 LCD_PrintString("counting : ");
						 if((Button_Read('F',4)==0 && (pause_flag == 0) )|| (Door_Status()== 1))//sw1 pressed for the first time)
						 {
							 ClearLcd();
							 Time_At_Pause = i+1;
							 pause_flag = 1 ;
							 LCD_PrintString("first step");
							 delay_inMilli(2000);
							 ClearLcd();
							 sprintf(t,"%d",i+1);
							 LCD_PrintString(t);
							 
							 while(!(Button_Read('F',4)== 0 && (pause_flag ==1)) || (Door_Status()== 1)) 
												
								{
									LedBlinking();
									if (Button_Read('F',0)== 0 ){ 
									ClearLcd();
									delay_inMilli(1000);
									count_down(Time_At_Pause) ;
													
								         }
									else if(!(Button_Read('F',0)== 0 ) && (Door_Status()== 1) ){
									ClearLcd();
									delay_inMilli(1000);
									 count_down(Time_At_Pause) ;
									}
							
					                         }
							SW1Pressed +=1;					
							break; 
						 }
			
			                        LedOn();
	                                       sprintf(t,"%d",i);
			                      LCD_PrintString(t);
		                              delay_inMilli(1000);
		                              ClearLcd();
 }
	 
	 
 
	if (Button_Read('F',4)== 0 && (pause_flag ==1)) { // sw1 -> second time 
			         
				
	    ClearLcd();
	    LCD_PrintString("cooking stopped");
		            //ideal state
	  while(!(Button_Read('F',0)== 0 && (pause_flag ==1) && (Door_Status()==1)))
		{	
		   LedBlinking();
		}
	}
	   if (Button_Read('F',0)== 0 && (Door_Status()==0)) {
			 // back to main
			 // switch_function() ;
		 }
	
	LedOff();
	delay_inMilli(1000);
        LedBlinking_withbuzzer();	
		
  }
