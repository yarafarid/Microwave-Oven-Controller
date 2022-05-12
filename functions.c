#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "LCDdriver.h"
#include "stdio.h"
#include "keypad.h"

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
 void count_down(unsigned char cook,unsigned char weight)
 {  unsigned char cook_time;
	 if(cook =='B')
	 {  cook_time=0.5*60*weight;
		 int i;
		  for(i=cook_time;i>0;i--)
		 { 
			 readyToPrint();
		   sendChar(cook_time +'0');
			 delay(1000);
			 ClearLcd();
			 
		 
		 }
	 }
	 else if(cook =='C')
	 {
		 int i;
		 cook_time=0.2*60*weight;
		 for(i=cook_time;i>0;i--)
		 { 
			 readyToPrint();
		   sendChar(cook_time +'0');
			 delay(1000);
			 ClearLcd();
		 
		 }
	 }
	 
 
 }
 
 
 
 void BeefOrChicken(unsigned char cook)
 { unsigned char weight;
	 do
	 {
	 if(cook=='B')
	 {
		 readyToPrint();
		 LCD_PrintString("Beef weight?");
	 }
	 else if (cook=='C')
	 {
		 readyToPrint();
		 LCD_PrintString("Chicken weight?");
	 
	 }
	 
	 
	  weight =keypad_Read(GPIO_PORTB_DATA_R);
	 
	 if(weight>=1&& weight<=9)
	 {  char weight_char[1];
		 
		 ClearLcd();
		 sprintf(weight_char, "%d", weight);
		 readyToPrint();
		 LCD_PrintString(weight_char);
		 delay(2000);
		 ClearLcd();
		 count_down(cook,weight);
		
	 }
	 else 
	 {
		 readyToPrint();
		 LCD_PrintString("Err");
		 delay(2000);
		 
 }
 
}while(~(weight>=1&& weight<=9));	 
		 
 
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
 

















 
