#include "tm4c123gh6pm.h"
#include "Initialization1.h"
#include "init2.h"
#include "Button.h" 
void keypad_Init (unsigned char portName){
     GPIO_Init('B');
     Port_Direction('B', 0x0F);
     GPIO_PullUp('B',4);
     GPIO_PullUp('B',5);
     GPIO_PullUp('B',6);
     GPIO_PullUp('B',7); 
} 
 
unsigned char keypad_Read(unsigned char portName){
     unsigned char keys[4][4]=  
     { 
         {'1','2','3','A'},
         {'4','5','6','B'},
         {'7','8','9','C'},
         {'*','0','#','D'}
     };
   
    char row, col, x;
    char returnValue = 0xFF; // an indicator that nothing was pressed on the keypad
    for (row = 0; row<4; row ++) { 
    Write_LS('B',0xFF);
    GPIO_PinData('B',row,0);
         for(col=0; col<=3; col++){
    x=GPIO_ReadPin('B', col+4);
    if(x==0){
        returnValue = keys[row][col];
        break;
         }
    if(x==0) break;
    return returnValue;
       }
    }
	}
