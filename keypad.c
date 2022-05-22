#include "tm4c123gh6pm.h"
#include "init2.h"
#include "Initialization1.h"
#include "stdint.h"



void RowKeypad_Init(){
	
		GPIO_Init('C');
		GPIO_PinDirection('C',4 , 1);
		GPIO_PinDirection('C',5 , 1);
		GPIO_PinDirection('C',6 , 1);
		GPIO_PinDirection('C',7 , 1);
	
}
void ColKeypad_Init(){
	
		GPIO_Init('E');
		GPIO_PinDirection('E',0 , 0);
		GPIO_PinDirection('E',1 , 0);
		GPIO_PinDirection('E',2 , 0);
		GPIO_PinDirection('E',3 , 0);
		GPIO_PORTE_PDR_R |= 0x0F;
}


void row_Init(unsigned short col){
		GPIO_PORTC_DATA_R = (1<<(col+4));
}

unsigned short GPIO_portE_DATA(){
		return (GPIO_PORTE_DATA_R & 0x0F);
}


unsigned char keys[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};


char keypad_Read(void){
		while(1){
			unsigned short row,col;
				for (row=0;row<4;row++){
						row_Init(row);
						delay_inMicro(2);
						for(col=0;col<4;col++){
								if(GPIO_portE_DATA() & (1<<col)){
										return keys[row][col];
								}
						  }
			    	}
		      }
}

  
