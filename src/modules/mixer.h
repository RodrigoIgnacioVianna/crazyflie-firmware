#ifndef mixer_h
#define mixer_h
#include "mbed.h"
#include "crazyflie.h"

//Mixer class
class Mixer
{
public:
    //Class constructor
    Mixer();
    //Actuate motors with desired total thrust force (N) and torques (N.m)
    void actuate(float f_t, float tau_phi, float tau_theta,float tau_psi);
    //Arm and disarm mixer
    void arm();
    void disarm();
    //Blink red LEDs
    void blink_reds();
    
private:
    //Motors PWM outputs
    PwmOut motor1, motor2, motor3, motor4;
    //Angular Velocities (rad/s)
    float omega_1, omega_2, omega_3, omega_4;
    // Convert total thrust force (N) and torques (N.m) to angular velocities (rad/s)
    void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
    //Convert desired angular velocity (rad/s) to PWM signal (%)
    float control_motor(float omega_r);
    //Armed or not variable
    bool armed;
    //LEDs
    DigitalOut led_vermelho_L;//,led_vermelho_R;
    //int tempo;
    
};

#endif

