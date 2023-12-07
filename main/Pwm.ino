#include  "Pwm.h"

// Function to initialize the PWM module
void PWM_Init(){
  
  // Set the pin direction for the PWM output
  DIO_SetPinDirection(DIO_PORTB, 3, DIO_OUTPUT);       //Fast PWM output at OC2A pin

  //Non-Inverting Fast PWM mode 3 using OCR A unit	
  SET_BIT(TCCR2A, COM2A1);
  SET_BIT(TCCR2A, WGM01);
  SET_BIT(TCCR2A, WGM00);
  //No-Prescalar
  SET_BIT(TCCR2B, CS00);          

}
// Function to set the duty cycle of the PWM signal
void Pwm_SetDutyCycle(char duty){
    OCR2A = duty;
}