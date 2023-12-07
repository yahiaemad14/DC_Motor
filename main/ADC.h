#ifndef __ADC__
#define __ADC__

// Function prototype for initializing the ADC
void Adc_Init(void);

// Function prototype for Reading the ADC channel
unsigned short Adc_ReadChannel(unsigned char channel);

#endif