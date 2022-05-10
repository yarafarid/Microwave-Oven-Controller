#include "tm4c123gh6pm.h"
#include "stdint.h"

 
 void systick_init(void)
 {
	 NVIC_ST_CTRL_R=0;
	 NVIC_ST_RELOAD_R=0X00FFFFFF;
	 NVIC_ST_CURRENT_R=0;
   NVIC_ST_CTRL_R=0X05;
	 
 }
 
 
 void systick_wait_1ms()
 {
	 	NVIC_ST_RELOAD_R=16000-1;
	  NVIC_ST_CURRENT_R=0;
	  while((NVIC_ST_CTRL_R&0x00010000)==0){};
	 
	 
 }
 void delay(uint32_t time)
 {
	 uint32_t i;
	 for(i=0;i<time;i++)
	 {
		 systick_wait_1ms();
	 
	 }
 
 
 }