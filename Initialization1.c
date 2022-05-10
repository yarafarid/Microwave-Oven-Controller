#include "tm4c123gh6pm.h"
#include "macros.h"
#include <stdint.h>
 

void GPIO_PinDirection (unsigned char PortName, unsigned char PinNumber, unsigned char Direction)
{
	switch(PortName)
	{
		case 'A':
		case 'a':
		{
			if(Direction == 1)
			{
				SET_BIT( GPIO_PORTA_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTA_DIR_R, PinNumber)
			}
			break;
		}
		
		case 'B':
		case 'b':
		{
			if(Direction == 1)
			{
				SET_BIT (GPIO_PORTB_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTB_DIR_R, PinNumber)
			}
			break;
		}
		
		case 'C':
		case 'c':
		{
			if(Direction == 1)
			{
				SET_BIT (GPIO_PORTC_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTC_DIR_R, PinNumber)
			}
			break;
		}
		
		case 'D':
		case 'd':
		{
			if(Direction == 1)
			{
				SET_BIT (GPIO_PORTD_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTD_DIR_R, PinNumber)
			}
			break;
		}
	
		case 'E':
		case 'e':
		{
			if(Direction == 1)
			{
				SET_BIT (GPIO_PORTE_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTE_DIR_R, PinNumber)
			}
			break;
		}
		
		case 'F':
		case 'f':
		{
			if(Direction == 1)
			{
				SET_BIT (GPIO_PORTF_DIR_R, PinNumber)
			}
			else 
			{
				CLEAR_BIT (GPIO_PORTF_DIR_R, PinNumber)
			}
			break;
		}
			
	}
}



void GPIO_PinToggle (unsigned char PortName, unsigned char PinNumber)
{
	switch(PortName)
	{
		case 'A':
		case 'a':
		{
			TOG_BIT (GPIO_PORTA_DATA_R, PinNumber)
			break;
		}
		
		case 'B':
		case 'b':
		{
			TOG_BIT (GPIO_PORTB_DATA_R, PinNumber)
			break;
		}
		
		case 'C':
		case 'c':
		{
			TOG_BIT (GPIO_PORTC_DATA_R, PinNumber)
			break;
		}
		
		case 'D':
		case 'd':
		{
			TOG_BIT (GPIO_PORTD_DATA_R, PinNumber)
			break;
		}
		
		case 'E':
		case 'e':
		{
			TOG_BIT (GPIO_PORTE_DATA_R, PinNumber)
			break;
		}
		
		case 'F':
		case 'f':
		{
			TOG_BIT (GPIO_PORTF_DATA_R, PinNumber)
			break;
		}
	}
}


void Port_Write (unsigned char PortName, unsigned char Data)
{
	switch(PortName)
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R = Data;
			break;
		}
		
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R = Data;
			break;
		}
		
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R = Data;
			break;
		}
		
		case 'D':
		case 'd':
		{
			GPIO_PORTC_DATA_R = Data;
			break;
		}
		
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R = Data;
			break;
		}
		
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R = Data;
			break;
		}
	}
}


unsigned char Port_Read (unsigned char PortName)
{
	switch(PortName)
	{
		case 'A':
		case 'a':
		{
			return GPIO_PORTA_DATA_R;
		
		}
    
		case 'B':
		case 'b':
		{
			return GPIO_PORTB_DATA_R;
			
		}
		
		case 'C':
		case 'c':
		{
			return GPIO_PORTC_DATA_R;
		
		}
		
		case 'D':
		case 'd':
		{
			return GPIO_PORTD_DATA_R;
			
		}
		
		case 'E':
		case 'e':
		{
			return GPIO_PORTE_DATA_R;
		
		}
		
		case 'F':
		case 'f':
		{
			return GPIO_PORTF_DATA_R;
			
		}
	}
}


void Write_MS (unsigned char PortName, unsigned char Data)
{ 
	Data <<= 4;
	switch (PortName)
	{
		case 'A':
		case 'a':
		{
			GPIO_PORTA_DATA_R &= 0x0F;
			GPIO_PORTA_DATA_R |= Data;
			break;
		}
		case 'B':
		case 'b':
		{
			GPIO_PORTB_DATA_R &= 0x0F;
			GPIO_PORTB_DATA_R |= Data;
			break;
		}
		case 'C':
		case 'c':
		{
			GPIO_PORTC_DATA_R &= 0x0F;
			GPIO_PORTC_DATA_R |= Data;
			break;
		}
		case 'D':
		case 'd':
		{
			GPIO_PORTD_DATA_R &= 0x0F;
			GPIO_PORTD_DATA_R |= Data;
			break;
		}
		case 'E':
		case 'e':
		{
			GPIO_PORTE_DATA_R &= 0x0F;
			GPIO_PORTE_DATA_R |= Data;
			break;
		}
		case 'F':
		case 'f':
		{
			GPIO_PORTF_DATA_R &= 0x0F;
			GPIO_PORTF_DATA_R |= Data;
			break;
		}
	}
}







