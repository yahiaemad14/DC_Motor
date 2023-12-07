// Include the necessary header files
#include "BIT_MATH.h"
#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "FSC.h"
#include "DC_Motor.h"
#include "Pwm.h"



int main()
{
  // Initialize necessary Functions
  Adc_Init();                        /* Initialize ADC */
  LCD_Init();                        /* Initialize LCD */
  initIO();                          /* Initialize I/O */
  DC_Init();			                  /* Initialize DC Motor */
  PWM_Init();


  // Declare variables
  int x;
  int adc_reading;
  unsigned char buffer[6];
  float voltage;
  float temperature;
  float target_temperature ;
  int time,Left_Button,Select_Button = 0;
  int Right_Button =0;
  int temperature_controller;
  int Debounce=0;
  unsigned char Select;
  unsigned char Difference;
  int j =1;

  while(1)
  {
    while(1)
    {
      _delay_ms(100);
      adc_reading = Adc_ReadChannel(1);
      // Read ADC channel 1 and convert to voltage
      voltage = adc_reading * (5.0 / 1023.0);
      temperature = voltage * 100;
      if (j==1)
      {
        LCD_Clear();                         //clearing the LCD
        LCD_Command(0x80);                   // Set LCD cursor to the beginning of the first line
        LCD_String("Heater");                //Display "Heater" on LCD
        LCD_Command(0xC0);                   // Set LCD cursor to the beginning of the second line
        LCD_String("Cooler");                //Display "Cooler" on LCD
      }
      j=2;
      x = Adc_ReadChannel(0);                // Read the Adc analog signal from Channel "0" 
      if(x<140 && x>100)                     // Checking if it is the "Up" Button
      {
        LCD_Clear();
        LCD_Command(0x80);
        LCD_String(">");
        LCD_Command(0x14);                   //Shift the cursor one place to the right
        LCD_String("Heater");
        LCD_Command(0xC0);
        LCD_String("Cooler");              
        Select = 1;
      }
      else if (x<350 && x>280)                // Checking if it is the "Down" Button
      {
        LCD_Clear();
        LCD_Command(0x80);
        LCD_String("Heater");
        LCD_Command(0xC0);
        LCD_String(">");
        LCD_Command(0x14);
        LCD_String("Cooler");
        Select = 2;
      }
      //Debounce++;
      //if(x>700 && x<800 && Select ==1 && Debounce>=500)

      // Checking if the Select button is pressed 
      if(x>700 && x<800 && Select ==1 )                        //if it is Heating Mode Set the target temperature as the room temperature + 10
      {
        target_temperature = temperature+10;
        //Debounce=0;
        break;                                                 // break from the Loop
      }
      else if(x>700 && x<800 && Select ==2 )
      //else if(x>700 && x<800 && Select ==2 && Debounce>=500)
      {
        target_temperature = temperature-10;                      //if it is Cooling Mode Set the target temperature as the room temperature - 10
        //Debounce=0;
        break;
      }
    }
    while(1)
    {
      if (time >= 100)                                        //Reading the Room temperature every 100 cycle 
      {
        adc_reading = Adc_ReadChannel(1);
        // Read ADC channel 1 and convert to voltage
        voltage = adc_reading * (5.0 / 1023.0);
        temperature = voltage * 100;                          // Converting the analog reading into temperature 
        time = 0;
      }
      time++;


      LCD_Command (0x80);                                       // Set LCD cursor to the beginning of the first line
      LCD_String("Room Temp:");                                 // Display Room Temp: on LCD
      floatToString(temperature, buffer, 2);                    // Convert the float to string with 2 decimal places and save it in the buffer array
      LCD_String(buffer);                                       // Display The value of temperature on LCD
      LCD_Command(0xC0);		                                    // Set LCD cursor to the beginning of the second line
	    LCD_String("Target Temp:");                               // Display Target Temp: on LCD
      floatToString(target_temperature, buffer, 2);             // Convert the float to string with 2 decimal places and save it in the buffer array
      LCD_String(buffer);                                       // Display The value of target_temperature on LCD
    
      temperature_controller = Adc_ReadChannel(0);
      Difference = temperature - target_temperature;
      if (target_temperature > temperature)                     //heating mode
      {
        DIO_SetPinValue(DIO_PORTB, 4, DIO_LOW);                 //turn off the blue LED
        DIO_SetPinValue(DIO_PORTB, 5, DIO_HIGH);                //turn on the red LED
        DC_Stop(0);
        if (Difference>=1)
        {
          DC_Start(0, DIRECTION_CW, 160);
        }
        else if (Difference>=2)
        {
          DC_Start(0, DIRECTION_CW, 180);
        }
        else if (Difference>=4)
        {
          DC_Start(0, DIRECTION_CW, 200);
        }
        else if (Difference>=6)
        {
          DC_Start(0, DIRECTION_CW, 220);
        }
        else if (Difference>8)
        {
          DC_Start(0, DIRECTION_CW, 240);
        }
        else if (Difference=0)
        {
          DC_Stop(0);
        }
      }
      if (target_temperature < temperature)                       //Cooling Mode
      {
        DIO_SetPinValue(DIO_PORTB, 4, DIO_HIGH);                  //turn on the blue LED
        DIO_SetPinValue(DIO_PORTB, 5, DIO_LOW);                   //turn off the red LED
        DC_Stop(0);
        if (Difference>=1)
        {
          DC_Start(0, DIRECTION_CCW, 160);
        }
        else if (Difference>=2)
        {
          DC_Start(0, DIRECTION_CCW, 180);
        }
        else if (Difference>=4)
        {
          DC_Start(0, DIRECTION_CCW, 200);
        }
        else if (Difference>=6)
        {
          DC_Start(0, DIRECTION_CCW, 220);
        }
        else if (Difference>8)
        {
          DC_Start(0, DIRECTION_CCW, 240);
        }
        else if (Difference=0)
        {
          DC_Stop(0);
        }
      } 
      if (Right_Button >= 5 && temperature_controller <60 )
      {
        target_temperature++;
        Right_Button=0;                                    //debouncing variable
      }
      else if (Left_Button >= 5 && temperature_controller < 600 && temperature_controller > 350 )
      {
        if(target_temperature>0)
        {
          target_temperature--;
        }
        Left_Button=0;                                     //debouncing variable
      }
      
      if (temperature_controller>700 &&temperature_controller<1000 &&Select_Button>=5)         // Checking if the Select button is pressed 
      {
        j=1;
        Select_Button=0;                                 //debouncing variable
        break;                                           //break the loop
      }
      Select_Button++;                        
      Right_Button++;
      Left_Button++;
    }
  }
  return 0;
}