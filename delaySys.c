#include "tm4c123gh6pm.h"


void SysTick_Wait(unsigned int delay){
		NVIC_ST_CTRL_R = 0;
		NVIC_ST_RELOAD_R = delay - 1;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R = 0x00000005;
		while((NVIC_ST_CTRL_R & 0x00010000)==0){}
}
void delay_inMilli(unsigned int delay){
		unsigned int i;
		for(i = 0;i<delay;i++){
			SysTick_Wait(80000/5);
		}
}
void delay_inMicro(unsigned int delay){
		unsigned int i;
		for(i = 0;i<delay;i++){
			SysTick_Wait(16);
		}
}