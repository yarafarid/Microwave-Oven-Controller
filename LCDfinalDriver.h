void LCD_init(void);
void LCD_Cmd(unsigned char command);
void LCD_PrintString(char *String);
void readyToPrint(void);
static void CREATEpulse (void);// give pulse after any print command
void sendChar(unsigned char ch);	
void ClearLcd(void);
void ForceCursor(unsigned char row,unsigned char col);//rows are 1,2 col 1 to 18
