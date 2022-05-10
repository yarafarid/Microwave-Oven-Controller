#include"tm4c123gh6pm"
void Button_Init(unsigned char portName , unsigned char pinNo);
unsigned char Button_Read(unsigned char portName , unsigned char pinNo);
void Button_Init_PUll_UP(unsigned char portName , unsigned char pinNo);



void Button_Init(unsigned char portName , unsigned char pinNo){

	PORT_Init(portname) ;  // OR INTIALIZE ALL PORTS AS DIGITAL IN MAIN
	DIO_vSETbit_DIR(portName, pinNo , 0); // DIR = 0 , SINCE BUTTON IS INPUT
}

unsigned char Button_Read(unsigned char portName , unsigned char pinNo){
 return DIO_u8readbit(portName , pinNo) ;
}


void Button_Init_PUll_UP(unsigned char portName , unsigned char pinNo){
	DIO_vEnablePullup(portName,  pinNo) ;
	PORT_Init(portname) ;  // OR INTIALIZE ALL PORTS AS DIGITAL IN MAIN
	DIO_vSETbit_DIR(portName, pinNo , 0); // DIR = 0 , SINCE BUTTON IS INPUT
}
