#include "tm4c123gh6pm.h"
#include "init2.h"
#include "Initialization1.h"
#include "macros.h"
#include "LCDdriver.h"

void delay_inMilli(int n);
void delay_inMicro(int n);
void LCD_init(void);
void LCD_Cmd(unsigned char command);
void LCD_PrintString(char *String);
void readyToPrint(void);// must call it before print 
static void CREATEpulse (void);// give pulse after any print command
void sendChar(unsigned char ch);	
void ClearLcd(void);
void ForceCursor(unsigned char row,unsigned char col);//rows are 1,2 col 1 to 18

void SystemInit(){}


void LCD_init()
{
  GPIO_Init('A');
	GPIO_Init('E');
	GPIO_PinDirection ('E', 1, 1);//data port
	GPIO_PinDirection ('E', 2, 1);//data port
	GPIO_PinDirection ('E', 4, 1);// RS
	GPIO_PinDirection ('E', 5, 1);//E
  Port_Direction('A', 0XFF);
	
	
	//LCD
	delay_inMilli(20); //let lcd to be on
	LCD_Cmd(0x38); //8-bits,2 display lines
		delay_inMilli(2);
	LCD_Cmd(0x01); //clr display
		delay_inMilli(10);
	LCD_Cmd(0x0C); //cursor off
		delay_inMilli(2);
	LCD_Cmd(0x06); //entry mode
		delay_inMilli(2);
	
}
 
void LCD_Cmd(unsigned char command)
{

	Port_Write ('A',command );
	GPIO_PinData('E', 1, command);//PIN E1
	GPIO_PinData('E', 2, command);//PIN E2
	GPIO_PinData('E', 4, 0);// RS=0
	CREATEpulse();
	delay_inMilli(2);

} 

void sendChar(unsigned char ch)
{

	Port_Write ('A',ch);
	GPIO_PinData('E', 1, ch);//PIN E1
	GPIO_PinData('E', 2, ch);//PIN E2
	GPIO_PinData('E', 4, 1);// RS=1
	CREATEpulse();
	delay_inMilli(2);
	
	
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
		sendChar(*String);
		String++;
	}
}

void readyToPrint(void){
LCD_Cmd(0x01); //to clear display
delay_inMilli(10);	
LCD_Cmd(0x80);// force cursor to the beginning of the line
delay_inMilli(700);
}

static void CREATEpulse (void){
GPIO_PinData('E', 5, 1);
delay_inMilli(3);
GPIO_PinData('E', 5, 0);
delay_inMilli(3);
}
void ClearLcd(void){
LCD_Cmd(0x01);//to clear display
delay_inMilli(10);	
}
void ForceCursor(unsigned char row,unsigned char col){
char x = 0;
if (row==1){
	x = (0x80)+col-1;
}	
else if(row==2){
  x = (0xC0)+col-1;
}	
else
	x = (0x80);
LCD_Cmd(x);
delay_inMilli(2);
}
