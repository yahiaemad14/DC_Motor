void floatToString(float value, char* buffer, int decimalPlaces) {
  // Handle negative numbers
  if (value < 0) {
    *buffer = '-';        // Add '-' character to the buffer  
    buffer++;             // Move the buffer pointer to the next position
    value = -value;       // Make the value positive  
  }

  // Convert the integer part to string
  unsigned long integerValue = (unsigned long)value;                                                     // Extract the integer part
  unsigned long decimalValue = (unsigned long)((value - integerValue) * pow(10, decimalPlaces));         // Extract the decimal part

  // Handle the integer part
  unsigned long divisor = 1;
  while (divisor <= integerValue / 10) {
    divisor *= 10;                                   // Find the largest power of 10 that is less than or equal to the integer value
  }

  while (divisor > 0) {
    *buffer = '0' + (integerValue / divisor);        // Convert the digit to a character and store it in the buffer
    buffer++;                                        // Move the buffer pointer to the next position
    integerValue %= divisor;                         // Update the integer value to the remainder after division by the divisor
    divisor /= 10;                                   // Move to the next digit by dividing the divisor by 10
  }

  // Handle decimal places
  if (decimalPlaces > 0) {
    *buffer = '.';                                   // Add '.' character to the buffer
    buffer++;                                        // Move the buffer pointer to the next position

    divisor = 1;
    for (int i = 0; i < decimalPlaces; i++) {
      divisor *= 10;                                 // Calculate the divisor value for the decimal places
    }

    while (divisor > 0) {
      *buffer = '0' + (decimalValue / divisor);       // Convert the digit to a character and store it in the buffer
      buffer++;                                       // Move the buffer pointer to the next position
      decimalValue %= divisor;                        // Update the integer value to the remainder after division by the divisor
      divisor /= 10;                                  // Move to the next digit by dividing the divisor by 10
    }
  }

  // Null-terminate the string
  *buffer = '\0';                                      // Add null-terminating character to mark the end of the string
}