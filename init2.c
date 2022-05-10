#include "tm4c123gh6pm.h"
#include <stdint.h>

#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLEAR_BIT(reg,bit) reg &= ~(1<<bit)
#define TOG_BIfT(reg,bit) reg ^= (1<<bit)
#define READ_BIT(reg,bit) (reg&(1<<bit))>>bit

void GPIO_Init(unsigned char PortName){
	switch(PortName){
		case 'A':
		case 'a':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 0 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 0 )) == 0 );
			GPIO_PORTA_DEN_R = 0xFF;
			GPIO_PORTA_CR_R = 0xFF;
			GPIO_PORTA_LOCK_R = 0x4C4F434B;
			GPIO_PORTA_AFSEL_R = 0x00;
			GPIO_PORTA_AMSEL_R = 0x00;
			break;
		}
		case 'B':
		case 'b':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 1 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 1 )) == 0 );
			GPIO_PORTB_DEN_R = 0xFF;
			GPIO_PORTB_CR_R = 0xFF;
			GPIO_PORTB_LOCK_R = 0x4C4F434B;
			GPIO_PORTB_AFSEL_R = 0x00;
			GPIO_PORTB_AMSEL_R = 0x00;
			break;
		}
		case 'C':
		case 'c':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 2 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 2 )) == 0 );
			GPIO_PORTC_DEN_R = 0xFF;
			GPIO_PORTC_CR_R = 0xFF;
			GPIO_PORTC_LOCK_R = 0x4C4F434B;
			GPIO_PORTC_AFSEL_R = 0x00;
			GPIO_PORTC_AMSEL_R = 0x00;
			break;
		}
		case 'D':
		case 'd':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 3 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 3 )) == 0 );
			GPIO_PORTD_DEN_R = 0xFF;
			GPIO_PORTD_CR_R = 0xFF;
			GPIO_PORTD_LOCK_R = 0x4C4F434B;
			GPIO_PORTD_AFSEL_R = 0x00;
			GPIO_PORTD_AMSEL_R = 0x00;
			break;
		}
		case 'E':
		case 'e':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 4 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 4 )) == 0 );
			GPIO_PORTE_DEN_R = 0xFF;
			GPIO_PORTE_CR_R = 0xFF;
			GPIO_PORTE_LOCK_R = 0x4C4F434B;
			GPIO_PORTE_AFSEL_R = 0x00;
			GPIO_PORTE_AMSEL_R = 0x00;
			break;
		}
		case 'F':
		case 'f':
		{
			SET_BIT( SYSCTL_RCGCGPIO_R , 5 );
			while( (READ_BIT(SYSCTL_PRGPIO_R , 5 )) == 0 );
			GPIO_PORTF_DEN_R = 0xFF;
			GPIO_PORTF_CR_R = 0xFF;
			GPIO_PORTF_LOCK_R = 0x4C4F434B;
			GPIO_PORTF_AFSEL_R = 0x00;
			GPIO_PORTF_AMSEL_R = 0x00;
			break;
		}
	}
}
void GPIO_PinData(unsigned char PortName, unsigned char PinNumber, unsigned char Data){
	switch(PortName){
		case 'A':
		case 'a':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTA_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTA_DATA_R , PinNumber );
			}
			break;
		}
		case 'B':
		case 'b':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTB_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTB_DATA_R , PinNumber );
			}
			break;
		}
		case 'C':
		case 'c':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTC_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTC_DATA_R , PinNumber );
			}
			break;
		}
		case 'D':
		case 'd':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTD_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTD_DATA_R , PinNumber );
			}
			break;
		}
		case 'E':
		case 'e':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTE_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTE_DATA_R , PinNumber );
			}
			break;
		}
		case 'F':
		case 'f':
		{
			if(Data==1){
				SET_BIT( GPIO_PORTF_DATA_R , PinNumber );
			}
			else{
				CLEAR_BIT( GPIO_PORTF_DATA_R , PinNumber );
			}
			break;
		}
	}
}
void Port_Direction(unsigned char PortName, unsigned char Direction){
	switch(PortName){
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DIR_R = Direction;
			break;
		}
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DIR_R = Direction;
			break;
		}
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DIR_R = Direction;
			break;
		}
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DIR_R = Direction;
			break;
		}
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DIR_R = Direction;
			break;
		}
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DIR_R = Direction;
			break;
		}
	}
}
unsigned char GPIO_ReadPin(unsigned char PortName, unsigned char PinNumber){
	switch(PortName){
		case 'A':
		case 'a':
		{
			return ( READ_BIT( GPIO_PORTA_DATA_R , PinNumber ) );
		}
		case 'B':
		case 'b':
		{
			return ( READ_BIT( GPIO_PORTB_DATA_R , PinNumber ) );
		}
		case 'C':
		case 'c':
		{
			return ( READ_BIT( GPIO_PORTC_DATA_R , PinNumber ) );
		}
		case 'D':
		case 'd':
		{
			return ( READ_BIT( GPIO_PORTD_DATA_R , PinNumber ) );
		}
		case 'E':
		case 'e':
		{
			return ( READ_BIT( GPIO_PORTE_DATA_R , PinNumber ) );
		}
		case 'F':
		case 'f':
		{
			return ( READ_BIT( GPIO_PORTF_DATA_R , PinNumber ) );
		}
	}
	return 0;
}
void GPIO_PullUp(unsigned char PortName, unsigned char PinNumber){
	switch(PortName){
		case 'A':
		case 'a':
		{
			SET_BIT( GPIO_PORTA_PUR_R , PinNumber );
			break;
		}
		case 'B':
		case 'b':
		{
			SET_BIT( GPIO_PORTB_PUR_R , PinNumber );
			break;
		}
		case 'C':
		case 'c':
		{
			SET_BIT( GPIO_PORTC_PUR_R , PinNumber );
			break;
		}
		case 'D':
		case 'd':
		{
			SET_BIT( GPIO_PORTD_PUR_R , PinNumber );
			break;
		}
		case 'E':
		case 'e':
		{
			SET_BIT( GPIO_PORTE_PUR_R , PinNumber );
			break;
		}
		case 'F':
		case 'f':
		{
			SET_BIT( GPIO_PORTF_PUR_R , PinNumber );
			break;
		}
	}
}
void Write_LS(unsigned char PortName, unsigned char Data){
	switch(PortName){
		case 'A':
		case 'a':
		{
			GPIO_PORTF_DATA_R &= 0xF0;
			GPIO_PORTF_DATA_R |= Data;
			break;
		}
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R &= 0xF0;
			GPIO_PORTB_DATA_R |= Data;
			break;
		}
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R &= 0xF0;
			GPIO_PORTC_DATA_R |= Data;
			break;
		}
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R &= 0xF0;
			GPIO_PORTD_DATA_R |= Data;
			break;
		}
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R &= 0xF0;
			GPIO_PORTE_DATA_R |= Data;
			break;
		}
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R &= 0xF0;
			GPIO_PORTF_DATA_R |= Data;
			break;
		}
	}
}
