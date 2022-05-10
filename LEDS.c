#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "init2.h"
#include "Initialization1.h"


void LED_Int(unsigned char portName,unsigned char pinNO)
{
	GPIO_PinDirection(portName,pinNO,1);//output

}
void LED_On(unsigned char portName,unsigned char pinNO)
{
	GPIO_PinData(portName,pinNO,1);
	
}
void LED_Off(unsigned char portName,unsigned char pinNO)
{
	GPIO_PinData(portName,pinNO,0);
	
}
void LED_Togl(unsigned char portName,unsigned char pinNO)
{
	GPIO_PinToggle(portName,pinNO);
	
}
