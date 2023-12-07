// Define constants for input and output directions
#define DIO_INPUT          0
#define DIO_OUTPUT         1
// Define constants for low and high pin values
#define DIO_LOW            0
#define DIO_HIGH           1
// Define constants for PORTB and PORTD
#define DIO_PORTB          2
#define DIO_PORTD          4

// Function prototype for setting pin direction
void DIO_SetPinDirection(unsigned char Port , int Pin , unsigned char Direction);
// Function prototype for setting pin value
void DIO_SetPinValue(unsigned char Port , int Pin , unsigned char Value);
// Function prototype for getting pin value
int DIO_GetPinValue(unsigned char Port , int Pin);

// Function prototype for initializing Input & Output
void initIO();