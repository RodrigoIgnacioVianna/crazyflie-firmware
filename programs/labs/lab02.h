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
motor.period(1.0/500.0);


float control_motor(float omega_r) {
    return omega_r*omega_r*a1+omega_r*a2;

}
int main()
{
    //turn on motor 1 with 1000 rad/s for 0.5s
    motor= control_motor(1000);
    wait(0.5);
    //Turn off motor 1
    motor=0.0;

    while(true)
    {
    }
       
        }
        

        
        
    

