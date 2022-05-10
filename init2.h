void GPIO_Init(unsigned char PortName);
void GPIO_PinData(unsigned char PortName, unsigned char PinNumber, unsigned char Data);
void Port_Direction(unsigned char PortName, unsigned char Direction);
unsigned char GPIO_ReadPin(unsigned char PortName, unsigned char PinNumber);
void GPIO_PullUp(unsigned char PortName, unsigned char PinNumber);
void Write_LS(unsigned char PortName, unsigned char Data);