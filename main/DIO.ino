// Function definition for setting pin direction
void DIO_SetPinDirection(unsigned char Port, int Pin, unsigned char Direction) {
  if (Direction == DIO_INPUT) {
    // Check the specified port and pin range for setting input direction
    switch (Port) {
      case DIO_PORTB:
        if ((Pin <= 5) && (Pin >= 0)) {  //As PORTB has 6 pins from 0 to 5
          CLR_BIT(DDRB, Pin);            // Clear the bit in DDRB to set it as input
        }
        break;

      case DIO_PORTD:
        if ((Pin <= 7) && (Pin >= 0)) {  //As PORTD has 8 pins from 0 to 7
          CLR_BIT(DDRD, Pin);            // Clear the bit in DDRD to set it as input
        }
        break;
    }
  } else if (Direction == DIO_OUTPUT) {
    // Check the specified port and pin range for setting output direction
    switch (Port) {
      case DIO_PORTB:
        if ((Pin <= 5) && (Pin >= 0)) {
          SET_BIT(DDRB, Pin);  // Set the bit in DDRB to set it as output
        }
        break;
      case DIO_PORTD:
        if ((Pin <= 7) && (Pin >= 0)) {
          SET_BIT(DDRD, Pin);  // Set the bit in DDRD to set it as output
        }
        break;
    }
  }
}

// Function definition for setting pin value
void DIO_SetPinValue(unsigned char Port, int Pin, unsigned char Value) {
  if (Value == DIO_LOW) {
    // Check the specified port and pin range for setting pin value to low
    switch (Port) {
      case DIO_PORTB:
        if ((Pin <= 5) && (Pin >= 0)) {
          CLR_BIT(PORTB, Pin);  // Clear the bit in PORTB to set it as low
        }
        break;
      case DIO_PORTD:
        if ((Pin <= 7) && (Pin >= 0)) {
          CLR_BIT(PORTD, Pin);  // Clear the bit in PORTD to set it as low
        }
        break;
    }
  } else if (Value == DIO_HIGH) {
    // Check the specified port and pin range for setting pin value to high
    switch (Port) {
      case DIO_PORTB:
        if ((Pin <= 5) && (Pin >= 0)) {
          SET_BIT(PORTB, Pin);  // Set the bit in PORTB to set it as high
        }
        break;
      case DIO_PORTD:
        if ((Pin <= 7) && (Pin >= 0)) {
          SET_BIT(PORTD, Pin);  // Set the bit in PORTD to set it as high
        }
        break;
    }
  }
}

// Function definition for getting pin value
int DIO_GetPinValue(unsigned char Port, int Pin) {
  int Local_Result;
  // Check the specified port and pin range for getting the pin value
  switch (Port) {
    case DIO_PORTB:
      if ((Pin <= 5) && (Pin >= 0)) {
        Local_Result = GET_BIT(PINB, Pin);  // Get the value of the specified bit in PORTB
      }
      break;
    case DIO_PORTD:
      if ((Pin <= 7) && (Pin >= 0)) {
        Local_Result = GET_BIT(PIND, Pin);  // Get the value of the specified bit in PORTD
      }
      break;
  }

  return Local_Result;
}

/* Function definition for initialize I/O */
void initIO() {

  // Set LED pin as output
  DIO_SetPinDirection(DIO_PORTB, 4, DIO_OUTPUT);
  DIO_SetPinDirection(DIO_PORTB, 5, DIO_OUTPUT);

}

