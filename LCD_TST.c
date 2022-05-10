#include "tm4c123gh6pm.h"
#include "stdint.h"
void delay_inMilli(int n);
void delay_inMicro(int n);
void LCD_init(void);
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_PrintString(char *String);
void readyToPrint(void);// must call it before print 


void SystemInit(){}

//	==============for testing================
int main(){
LCD_init();
while(1)
{
readyToPrint();

LCD_Data('T');
delay_inMilli(1);
LCD_Data('E');
delay_inMilli(1);
LCD_Data('S');
delay_inMilli(1);
LCD_Data('T');
delay_inMilli(500);
}
}//
	
void LCD_init()
{
	SYSCTL_RCGCGPIO_R |= 0x01; // Enable clock for portA
	while ((SYSCTL_PRGPIO_R & 0x00000002)==0){};  //wait til portA IS activated
	GPIO_PORTA_DIR_R |=0xE0; //PORTA controls RS,E and R/W
	GPIO_PORTA_DEN_R |=0xE0;
	//portB
	GPIO_PORTB_DIR_R |=0xFF; //PORTB D0-D7
	GPIO_PORTB_DEN_R |=0xFF; //PORTB D0-D7
	//LCD
	delay_inMilli(20); //let lcd to be on
	LCD_Cmd(0x38); //8-bits,2 display lines
	LCD_Cmd(0x06); //increments automatically
	LCD_Cmd(0x0F); //Turn on display(cursor starts blinking)
	LCD_Cmd(0x01); //clear display(CURSOR AT HOME)
}
 
void LCD_Cmd(unsigned char command)
{
	//initialization sequence
	GPIO_PORTA_DATA_R = 0; //RS=0, E=0, RW=0 (CMD MOD)
	GPIO_PORTA_DATA_R =command; //Rs in command mode
	GPIO_PORTA_DATA_R =0x80; //E=1 to secure command
	delay_inMicro(0);
	GPIO_PORTA_DATA_R =0;
	// TO Elimnate hardware delays
	if(command <4) 
	{
		delay_inMilli(2);
	}	
	else
	{	
		delay_inMicro(40); 
	}
} 
void LCD_Data(unsigned char data) 
	{
		GPIO_PORTA_DATA_R =0x20; //RS=1 (A5=1), E=0,RW=0
		GPIO_PORTA_DATA_R =data;
		GPIO_PORTA_DATA_R |= 0x80;// Enable
		GPIO_PORTA_DATA_R =0x00;
		delay_inMicro(0);
	}
void delay_inMilli(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}
 
void delay_inMicro(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3;j++)
{}
}
void LCD_PrintString(char *String)
{
	while(*String)// will stop when it reaches null terminator
	{
		LCD_Data(*String);
		String++;
	}
}

void readyToPrint(void){
LCD_Cmd(0x01); //to clear display
LCD_Cmd(0x80);// force cursor to the beginning of the line
delay_inMilli(700);
}