#ifndef __DC_MOTOR
#define __DC_MOTOR

// Definition of the DC motor rotation direction
typedef enum {
    DIRECTION_CW = 0,
    DIRECTION_CCW
} tenuDirection;

// Function to initialize the DC motor control module
void DC_Init();
// Function to start the DC motor with specified parameters
void DC_Start(unsigned char MotorID, tenuDirection Direction, unsigned char Speed);
// Function to stop the specified DC motor
void DC_Stop(unsigned char MotorID);

#endif