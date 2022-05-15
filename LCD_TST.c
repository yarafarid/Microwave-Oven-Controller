#include "tm4c123gh6pm.h"
#include "init2.h"
#include "Initialization1.h"
#include "macros.h"

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

	
#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Function_set_4bit 0x28
#define Function_set_8bit 0x38
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define Set5x7FontSize    0x20
#define FirstRow          0x80


void SystemInit(){}

//	==============for testing================
int main(){
	//LCD initialization
        GPIO_Init('A');
	GPIO_Init('B');
	GPIO_PinDirection ('A', 7, 1);// RS
	GPIO_PinDirection ('A', 6, 1);//E
        Port_Direction('B', 0XFF);
LCD_init();
while(1)
{
readyToPrint();

sendChar('T');
delay_inMilli(1);
sendChar('E');
delay_inMilli(1);
sendChar('S');
delay_inMilli(1);
sendChar('T');
delay_inMilli(500);
}
}
	
void LCD_init()
{

	//LCD
	delay_inMilli(30);//let lcd to be on
	delay_inMicro(2000);
	LCD_Cmd(0x38); //8-bits,2 display lines
		delay_inMilli(1);
	LCD_Cmd(0x0E); //clr display
		delay_inMilli(15);
	LCD_Cmd(0x02); //cursor off
		delay_inMilli(15);
	LCD_Cmd(0x06); //entry mode
		delay_inMilli(2);
}
 
void LCD_Cmd(unsigned char command)
{

Port_Write ('B',command );
	GPIO_PinData('A', 7, 0);// RS=0
	CREATEpulse();
	delay_inMilli(5);

} 

void sendChar(unsigned char ch)
{

	Port_Write ('B',ch);
	GPIO_PinData('A', 7, 1);// RS=1
	CREATEpulse();
	delay_inMilli(5);
	
	
}

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
GPIO_PinData('A', 6, 1);
delay_inMilli(3);
GPIO_PinData('A', 6, 0);
delay_inMilli(3);
}
void ClearLcd(void){
LCD_Cmd(clear_display);
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
