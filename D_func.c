#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "init2.h"
#include "Initialization1.h"
#include "Button.h"
#include "LCDfinalDriver.h"
#include <TM4C123.h>
#include "Io.h"
unsigned char valid(short Time) {
	
 short sec	= Time%100 ;
	
   if (Time>3000){
	   LCD_PrintString("Error please don't Exceed 30 minuites") ;
	     return 0;
	  }

	   if (sec > 59){
	     LCD_PrintString("Error please don't Exceed 59 seconds") ;
		   return 0;
	}
      	return 1 ;
}

void D_Init() {
	Button_Init_PUll_UP('F' , 0) ;
	Button_Init_PUll_UP('F' , 4) ;
	keypad_Init('B') ;
}

short D_pressed()
{
	unsigned char cnt = 0 , input ;	
	short time = 0 ;
  LCD_PrintString("Cooking Time ?") ;
	// some delay
	ClearLcd() ;
	LCD_PrintString("00:00") ;
	// some delay
	 ClearLcd() ;
	while (Button_Read('F',0)){ // while start button is not pressed take input from user
	
		if (!Button_Read('F',4)){ // if clear button is pressed
		ClearLcd() ;	
		time = 0 ; 
		cnt = 0 ;
		}
		
		if (cnt == 2) sendChar(':') ;
		else if (cnt == 4) break ;
		input = keypad_Read('B') ;
		time*=10 ;
		time += input ;
		cnt ++ ;
	  sendChar (input +'0') ;
	}
	
	if (!valid(time)){
	 D_pressed() ;
	}
	
	else  {
	short seconds = time%100;
	short Total_time_in_seconds = seconds + ((time/100)*60) ;
			//Total time in seconds is to be sent to count down function
		   return Total_time_in_seconds ;
	}
}