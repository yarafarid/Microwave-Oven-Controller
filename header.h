#include "stdint.h"

void SystemInit1(void);
void SW1_Init();
unsigned char SW1_Input(void);
unsigned char SW2_Input(void);
void systick_init(void);
void RGB_Output(unsigned char led);
void RGB_close(unsigned char led);
void systick_wait_1ms();
void delay(uint32_t time);