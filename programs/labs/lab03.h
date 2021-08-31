#include "mbed.h"
#include "crazyflie.h"
// Define all LEDs as digital output objects
DigitalOut led_vermelho_L(LED_RED_R,!false);
DigitalOut led_vermelho_R(LED_RED_L,!false);
DigitalOut led_azul(LED_BLUE_L,false);
DigitalOut led_verde_L(LED_GREEN_L,!false);
DigitalOut led_verde_R(LED_GREEN_R,!false);
// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);



float control_motor(float omega_r) {
    return omega_r*omega_r*a1+omega_r*a2;

}
int main()
{
    //LIGAR MOTORES
    motor1= control_motor(2200);
    motor1.period(1.0/500.0);
    motor2= control_motor(2200);
    motor2.period(1.0/500.0);
    motor3= control_motor(2200);
    motor3.period(1.0/500.0);
    motor4= control_motor(2200);
    motor4.period(1.0/500.0);
    wait(8);
    //Turn off motor 1
    motor1=0.0;
    motor2=0.0;
    motor3=0.0;
    motor4=0.0;

    while(true)
    {
    }
       
        }
        

        
        
    

