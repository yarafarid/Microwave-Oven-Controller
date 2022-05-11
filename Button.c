#include "tm4c123gh6pm.h"
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "init2.h"
#include "Initialization1.h"

void Button_Init(unsigned char portName , unsigned char pinNo){

	GPIO_Init(portName) ;  // OR INTIALIZE ALL PORTS AS DIGITAL IN MAIN
	GPIO_PinDirection(portName, pinNo , 0); // DIR = 0 , SINCE BUTTON IS INPUT
}

unsigned char Button_Read(unsigned char portName , unsigned char pinNo){
 return GPIO_ReadPin(portName , pinNo) ;
}


void Button_Init_PUll_UP(unsigned char portName , unsigned char pinNo){
	GPIO_PullUp(portName,  pinNo) ;
	GPIO_Init(portName) ;  // OR INTIALIZE ALL PORTS AS DIGITAL IN MAIN
	GPIO_PinDirection(portName, pinNo , 0); // DIR = 0 , SINCE BUTTON IS INPUT
}
