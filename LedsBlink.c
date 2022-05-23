#include "Initialization1.h"
#include "init2.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "delaySys.h"
#include "Buzzer.h"

void LedOn (void) {
		GPIO_PinDirection ('F', 1, 1);
		GPIO_PinDirection ('F', 2, 1);
		GPIO_PinDirection ('F', 3, 1);
		GPIO_PinData('F', 1, 1);
		GPIO_PinData ('F', 2, 1);
		GPIO_PinData ('F', 3, 1);
}
void LedOff (void) {
		GPIO_PinDirection ('F', 1, 1);
		GPIO_PinDirection ('F', 2, 1);
		GPIO_PinDirection ('F', 3, 1);
		GPIO_PinData('F', 1, 0);
		GPIO_PinData ('F', 2, 0);
		GPIO_PinData ('F', 3, 0);
}

void LedBlinking_withbuzzer (void){
	int j;
	Buzzer_ON();
	for(j=0; j<6; j++)
		{
				Port_Write('F', (Port_Read ('F') ^ 0x0E));
				delay_inMilli(500);
		}
	Buzzer_OFF();
}
void LedBlinking (void){
	int j;
	for(j=0; j<2; j++)
		{
				Port_Write('F', (Port_Read ('F') ^ 0x0E));
				delay_inMilli(500);
		}
}
