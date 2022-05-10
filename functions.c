#include "tm4c123gh6pm.h"
#include "stdint.h"
#define SET_BIT(reg,bit){reg|=1<<bit;}
#define CLEAR_BIT(reg,bit){reg&=~(1<<bit);}
#define TOG_BIT(reg,bit){red^=1<<bit;}
#define READ_BIT(reg,bit){reg&(1<<bit)>>bit;}



	

//GPIO.c
void PORT_Int(unsigned char potrName);
void DIO_vSETbit_DIR(unsigned char portName,unsigned char pinNO,unsigned char diraction);
void DIO_vWritebit_DATA(unsigned char portName,unsigned char pinNO,unsigned char data);
void DIO_vTOGbit(unsigned char portName,unsigned char pinNO);
void DIO_vSETpotr_DIR(unsigned char portName,unsigned char diraction);
void DIO_vWriteport_DATA(unsigned char portName,unsigned char data);
unsigned char DIO_u8Readbit_DATA(unsigned char portName,unsigned char pinNO);
unsigned char DIO_u8Readport_DATA(unsigned char portName );
void DIO_vEnablePullup(unsigned char portName,unsigned char pinNO);
void DIO_vWriteHighLlevel(unsigned char portName,unsigned char data);
void DIO_vWriteLowlevel(unsigned char portName,unsigned char data);
//LEDS.c
void LED_vInt(unsigned char portName,unsigned char pinNO)
{
	DIO_vSETbit_DIR(portName,pinNO,1);//output

}
void LED_vOn(unsigned char portName,unsigned char pinNO)
{
	DIO_vWritebit_DATA(portName,pinNO,1);
	
}
void LED_vOff(unsigned char portName,unsigned char pinNO)
{
	DIO_vWritebit_DATA(portName,pinNO,0);
	
}
void LED_vTog(unsigned char portName,unsigned char pinNO)
{
	 DIO_vTOGbit(portName,pinNO);
	
}

//switches 
void Buttom_vInt(unsigned char portName,unsigned char pinNO);
unsigned char Buttom_u8Read(unsigned char portName,unsigned char pinNO);
//keypad
void KeyPad_vInt(unsigned char portName);
unsigned char KeyPad_u8Read(unsigned char portName);

//lcd
void LCD_init();
void LCD_Cmd(unsigned char command);
void LCD_Data(unsigned char data);
void delay_inMilli(int n);
void delay_inMicro(int n);
void LCD_PrintString(char *String);
void readyToPrint(void);



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
 
 void BeefOrChicken(unsigned char cook)
 {
	 if(cook=='B')
		 
		 
 
 }
 
 
 
 
 
 
 
 
 
 
 int main(void)
 {
	
	 while(1)
	 { 
		 
	 }
		 
		 
	 
	 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
// void clear_dis()
// {};
// 
// 
// void B_C_choise(char x)
// {
//	 int number_weight;
//	 int choise;
//	 if(strcmp(&x,"B"))
//	 {
//		 printf("Beef weight?");
//		 choise=1;
//		 
//	 }
//	 else if(strcmp(&x,"A"))
//	 {
//		 printf("Chicken weight?");
//		 choise=0;
//	 
//	 }
//	 scanf("%d",&number_weight);
//	
//if(number_weight<=9 && number_weight>=1)
//	 {
//		 printf("%d",number_weight);
//	   delay(2000);
//     clear_dis();
//		 if(choise==1)//Beaf
//		 {
//			 int t=0.5*60*number_weight;
//			 NVIC_ST_RELOAD_R=t/(int)(1.25*pow(10,6));
//			 while((NVIC_ST_CTRL_R&0x00010000)==0)
//			 {
//				 printf("%d",NVIC_ST_CURRENT_R);
//			 }
//			  
//		 }
//		 else if(choise==0)
//		 {
//			 int t=0.5*60*number_weight;
//			 NVIC_ST_RELOAD_R=t/(int)(1.25*pow(10,6));
//			 while((NVIC_ST_CTRL_R&0x00010000)==0)
//			 {
//				 printf("%d",NVIC_ST_CURRENT_R);
//			 }

//		 }
//	 }		 
//else
//{	
//while(~(number_weight<=9 && number_weight>=1)){
//	
//		 printf("Err");
//	   delay(2000);
//     clear_dis();
//		 printf("enter weight");
//		 scanf("%d",&number_weight);

//	 
// }
//		 printf("%d",number_weight);
//	   delay(2000);
//     clear_dis();
//		 if(choise==1)//Beaf
//		 {
//			 int t=0.5*60*number_weight;
//			 NVIC_ST_RELOAD_R=t/(int)(1.25*pow(10,6));
//			 while((NVIC_ST_CTRL_R&0x00010000)==0)
//			 {
//				 printf("%d",NVIC_ST_CURRENT_R);
//			 }
//			  
//		 }
//		 else if(choise==0)
//		 {
//			 int t=0.5*60*number_weight;
//			 NVIC_ST_RELOAD_R=t/(int)(1.25*pow(10,6));
//			 while((NVIC_ST_CTRL_R&0x00010000)==0)
//			 {
//				 printf("%d",NVIC_ST_CURRENT_R);
//			 }
//		 } 
// 

// }
 

















 
