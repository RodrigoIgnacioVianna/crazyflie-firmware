#include "mbed.h"
#include "crazyflie.h"
// Definir motores como objetos PWM
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

//Definir velocidades angulares

float omega_1;
float omega_2;
float omega_3;
float omega_4;

//Converter  velocidade angular (rad/s) para PWM(%)
float control_motor(float omega_r) {
    return omega_r*omega_r*a1+omega_r*a2;
}

// Converter trust total (N) e torques (N.m) para velocidade angular (rad/s)

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
    float omega_1_sq= (1/(4*kl))*f_t-(1/(4*kl*l))*tau_phi-(1/(4*kl*l))*tau_theta-(1/(4*kd))*tau_psi;
    float omega_2_sq= (1/(4*kl))*f_t-(1/(4*kl*l))*tau_phi+(1/(4*kl*l))*tau_theta+(1/(4*kd))*tau_psi;
    float omega_3_sq= (1/(4*kl))*f_t+(1/(4*kl*l))*tau_phi+(1/(4*kl*l))*tau_theta-(1/(4*kd))*tau_psi;
    float omega_4_sq= (1/(4*kl))*f_t+(1/(4*kl*l))*tau_phi-(1/(4*kl*l))*tau_theta+(1/(4*kd))*tau_psi;
    
    if(omega_1_sq<0){
        omega_1=0;
    }
    if(omega_1_sq>=0){
        omega_1 = sqrt(omega_1_sq);
    }
    if(omega_2_sq<0){
        omega_2=0;
    }
    if(omega_2_sq>=0){
        omega_2 = sqrt(omega_2_sq);
    }
    if(omega_3_sq<0){
        omega_3=0;
    }
    if(omega_3_sq>=0){
        omega_3 = sqrt(omega_3_sq);
    }
    if(omega_4_sq<0){
        omega_4=0;
    }
    if(omega_4_sq>=0){
        omega_4 = sqrt(omega_4_sq);
    }

}

// Atuar motores com a força total de truste desejada (N) e torques (N.M)
void actuate(float f_t, float tau_phi, float tau_theta,float tau_psi){
    mixer(f_t,tau_phi,tau_theta,tau_psi);
    motor1= control_motor(omega_1);
    motor2= control_motor(omega_2);
    motor3= control_motor(omega_3);
    motor4= control_motor(omega_4);
    
}

//Programa principal

int main()

{
    //setar frequências do PWM
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);
    //Atuar motor com 70% mg força total de truste (N) e torques iguais a zero (N.m)
    actuate(0,0,0,0.001);
    wait(5);
    //Desligar motores;
    actuate(0,0,0,0);
    //Terminar programa
    while(true){

    }

}





