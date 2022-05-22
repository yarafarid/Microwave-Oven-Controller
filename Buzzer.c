#include "Initialization1.h"
#include "init2.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

void Buzzer_Init(){
	GPIO_PinDirection ('D', 2 ,1) ;
}
void Buzzer_OFF() {
	GPIO_PinData('D', 2, 0);	
}
void Buzzer_ON() {
	GPIO_PinData('D', 2, 1);
}