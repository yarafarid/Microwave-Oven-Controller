#include "tm4c123gh6pm.h"
#include "stdint.h"
#include ""
#define SET_BIT(reg,bit){reg|=1<<bit;}
#define CLEAR_BIT(reg,bit){reg&=~(1<<bit);}
#define TOG_BIT(reg,bit){red^=1<<bit;}
#define READ_BIT(reg,bit){reg&(1<<bit)>>bit;}

void LED_Int(unsigned char portName,unsigned char pinNO)
{
	DIO_vSETbit_DIR(portName,pinNO,1);//output

}
void LED_On(unsigned char portName,unsigned char pinNO)
{
	DIO_vWritebit_DATA(portName,pinNO,1);
	
}
void LED_Off(unsigned char portName,unsigned char pinNO)
{
	DIO_vWritebit_DATA(portName,pinNO,0);
	
}
void LED_Togl(unsigned char portName,unsigned char pinNO)
{
	 DIO_vTOGbit(portName,pinNO);
	
}
