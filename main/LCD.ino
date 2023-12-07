#define LCD_Dir  DDRD			/* Define LCD data port direction */
#define LCD_Port PORTD		/* Define LCD data port */

#define RS_EN_Dir  DDRB		/* Define RS and En data port direction */
#define RS_EN_Port PORTB  /* Define RS and En port */
#define RS PB0				    /* Define Register Select pin */
#define EN PB1 				    /* Define Enable signal pin */

// Function definition for Sending commands to the LCD
void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);        /* sending upper nibble */	
	CLR_BIT(RS_EN_Port, RS);                             /* RS=0, command reg. */		                         
	SET_BIT(RS_EN_Port, EN);                             /* Enable pulse */
  _delay_us(1);
  CLR_BIT(RS_EN_Port, EN);                             /*Disable pulse */

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);          /* sending lower nibble */
	SET_BIT(RS_EN_Port, EN);                             /* Enable pulse */
  _delay_us(1);
	CLR_BIT(RS_EN_Port, EN);                             /*Disable pulse */
  _delay_ms(2);
}

// Function definition for sending charachter to the LCD
void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);         /* sending upper nibble */                    
	SET_BIT(RS_EN_Port, RS);                              /* RS=1, data reg. */
	SET_BIT(RS_EN_Port, EN);                              /* Enable pulse */
  _delay_us(1);
  CLR_BIT(RS_EN_Port, EN);                              /*Disable pulse */

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4);           /* sending lower nibble */
	SET_BIT(RS_EN_Port, EN);                              /* Enable pulse */
  _delay_us(1);
	CLR_BIT(RS_EN_Port, EN);                              /*Disable pulse */
  _delay_ms(2);
}

// Function definition for initializing the LCD
void LCD_Init (void)		
{
	LCD_Dir = 0xFF;			    /* Make LCD port direction as o/p */
    SET_BIT(RS_EN_Dir, RS);
    SET_BIT(RS_EN_Dir, EN);

	_delay_ms(20);			    /* LCD Power ON delay always >15ms */
	
	LCD_Command(0x02);		  /* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);      /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);      /* Display on cursor off */
	LCD_Command(0x06);      /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);      /* Clear display screen*/
  LCD_Command(0xC0);      /* Force the cursor to the beginning of the 2nd line */
	_delay_ms(2);
}

// Function definition for Sending string to the LCD
void LCD_String (char *str)		
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Loop to send each char of string till the NULL */
	{
		LCD_Char (str[i]);      /* Calling LCD_Char function to send every char */
	}
}

// Function definition for sending special charachter
void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	  LCD_Command((pos & 0x0F)|0x80);	                  /* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	  LCD_Command((pos & 0x0F)|0xC0);	                  /* Command of first row and required position<16 */
    
	LCD_String(str);	                              	/* Calling LCD string function */
}

// Function definition for clearing the LCD
void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}