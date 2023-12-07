#ifndef __LCD__
#define __LCD__ 

// Function prototype for Sending commands to the LCD
void LCD_Command(unsigned char cmnd);
// Function prototype for initializing the LCD
void LCD_Init (void);
// Function prototype for sending charachter to the LCD
void LCD_Char (unsigned char char_data);
// Function prototype for sending string to the LCD
void LCD_String (char *str);
// Function prototype for sending special charachter to the LCD
void LCD_String_xy (char row, char pos, char *str);
// Function prototype for clearing the LCD screen
void LCD_Clear();

#endif 