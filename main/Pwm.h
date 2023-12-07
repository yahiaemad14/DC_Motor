#ifdef __PWM__
#define __PWM__
// Function to initialize the PWM module
void PWM_Init(void);
// Function to set the duty cycle of the PWM signal
void Pwm_SetDutyCycle(unsigned char duty);

#endif
