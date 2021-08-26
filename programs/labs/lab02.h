#include "mbed.h"
#include "crazyflie.h"
// Define all LEDs as digital output objects
DigitalOut led_vermelho_L(LED_RED_R,!false);
DigitalOut led_vermelho_R(LED_RED_L,!false);
DigitalOut led_azul(LED_BLUE_L,false);
DigitalOut led_verde_L(LED_GREEN_L,!false);
DigitalOut led_verde_R(LED_GREEN_R,!false);
// Define all motors as PWM objects
PwmOut motor(MOTOR1);


float control_motor(float omega_r) {
    return omega_r*omega_r*a1+omega_r*a2;

}
int main()
{
   
        
        }
    
    // Blink blue LED indicating inicialization (5 seconds)
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {
        if (fim==1){
            led_verde_L=!led_verde_L;
            wait(0.2);
            led_verde_R=!led_verde_R;
            wait(0.2);


        }
       
        }
        

        
        
    }

