unsigned char MotorArray[][2] = {
  {2, 3}
  };

// Function to initialize the DC motor control module
void DC_Init(){
  // Set the pin direction for the motor control pins as output
  DIO_SetPinDirection(DIO_PORTD, MotorArray[0][0], DIO_OUTPUT);
  DIO_SetPinDirection(DIO_PORTD, MotorArray[0][1], DIO_OUTPUT);
}

// Function to start the DC motor with specified parameters
void DC_Start(unsigned char MotorID, tenuDirection Direction, unsigned char Speed){
  
  if (Direction == DIRECTION_CW)
  {
    DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][0], DIO_HIGH);
    DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][1], DIO_LOW);
  }
  else if (Direction == DIRECTION_CCW)
  {
    DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][0], DIO_LOW);
    DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][1], DIO_HIGH);
  }
  Pwm_SetDutyCycle(Speed);
}
// Set both motor control pins to LOW to stop the motor
void DC_Stop(unsigned char MotorID)
{
  DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][0], DIO_LOW);
  DIO_SetPinValue(DIO_PORTD, MotorArray[MotorID][1], DIO_LOW);
}