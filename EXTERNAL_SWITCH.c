#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "init2.h"
#include "Initialization1.h"
#include "Button.h"
#include "LCDfinalDriver.h"
#include <TM4C123.h>
#include "Io.h"

void Door_Init() {
Button_Init('A' , 2);
GPIO_PinDirection ('A', 2 ,0) ;
}
void Check_The_Door(){
	while (!Button_Read('A', 2)){ // Switch is pressd--> open door
		LCD_PrintString("Please Close The Door") ;  //Not Ready to cook 
	} 
	LCD_PrintString("Enter a choice A, B, C or D") ;
}
unsigned char Door_Status()
{
	if (!Button_Read('A', 2)) {
		return 1 ;
	}
	else  {return 0;}
}
	/*Note : check in the main using while loop while door status ==1 -->open
	therefore user can't be able to enter an input
	
	while (Door_Status() == 1){
   please do not take input
	}
  check_the_door_function --> should be called after pressing any function
  as A , C , D in main 
*/
