
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