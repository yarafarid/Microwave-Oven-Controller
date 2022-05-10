void GPIO_PinDirection (unsigned char PortName, unsigned char PinNumber, unsigned char Direction);
	
void GPIO_PinToggle (unsigned char PortName, unsigned char PinNumber);

unsigned char Port_Read (unsigned char PortName)

void Port_Write (unsigned char PortName, unsigned char Data);

void Write_MS (unsigned char PortName, unsigned char Data);