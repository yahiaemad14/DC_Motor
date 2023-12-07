// Function definition for initializing the ADC
void Adc_Init(void)
{
    // Setting ( AREF = AVcc )
    SET_BIT(ADMUX, REFS0);        // Setting REFS0
    CLR_BIT(ADMUX, REFS1);        // Clearing REFS1
    
    SET_BIT(ADCSRA, ADEN);        //ADC Enable
    // ADC prescaler of 128
    // 16000000/128 = 125000
    SET_BIT(ADCSRA, ADPS0);
    SET_BIT(ADCSRA, ADPS1); 
    SET_BIT(ADCSRA, ADPS2);  
}

// Function definition for Reading the ADC
unsigned short Adc_ReadChannel(unsigned char ch)
{

  // select the corresponding channel 0~7
  // ANDing with ’7′ will always keep the value
  // of ‘ch’ between 0 and 7
  ch &= 0b00000111;              // AND operation with 7
  ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ORing
 
  SET_BIT(ADCSRA, ADSC);         // ADC Start Conversion 
 
  while(GET_BIT(ADCSRA, ADSC));  // wait for conversion to complete
  return (ADC);

}