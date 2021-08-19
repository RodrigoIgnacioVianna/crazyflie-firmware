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

// Main program e variáveis
int tempo = 0;
int fim = 0;
int main()
{
    while (tempo<=5){
            led_azul=!led_azul;
            tempo=tempo+1;
            wait(0.2);
        }
     if (tempo>5){
            led_vermelho_L= !true;
            led_vermelho_R=!true;
            motor1.period(1.0/400.0);
            motor1=0.2;
            wait(0.2);
            motor1=0;
            motor2.period(1.0/600.0);
            motor2=0.2;
            wait(0.2);
            motor2=0;
            motor3.period(1.0/800.0);
            motor3=0.2;
            wait(0.2);
            motor3=0;
            motor4.period(1.0/1000.0);
            motor4=0.2;
            wait(0.2);
            motor4=0;
            led_vermelho_L= true;
            led_vermelho_R=true;
            fim= 1;
        


        
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

