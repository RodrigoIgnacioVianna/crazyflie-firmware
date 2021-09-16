#include "mixer.h"
//Class constructor
Mixer :: Mixer(): motor1(MOTOR1),motor2(MOTOR2),motor3(MOTOR3),motor4(MOTOR4),led_vermelho_L(LED_RED_L)//,led_vermelho_R(LED_RED_R)
{
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);
    motor1=0;
    motor2=0;
    motor3=0;
    motor4=0;
}
//Blink red LEDs
// , LED_GREEN_L, LED_GREEN_R;
void Mixer :: blink_reds(){
  //  while(tempo<=5){
   // led_vermelho_L=!led_vermelho_L;
   // wait(0.5);
   // tempo++;

    //}
    led_vermelho_L=0;
    wait(0.5);
    led_vermelho_L=1;
    wait(0.5);
    led_vermelho_L= 0;
    wait(0.5);
    led_vermelho_L=1;
    wait(0.5);
    led_vermelho_L= 0;
    wait(0.5);
    led_vermelho_L=1;
    wait(0.5);
    led_vermelho_L= 0;
    wait(0.5);
    led_vermelho_L=1;
    wait(0.5);
    led_vermelho_L= 0;
    wait(0.5);
    led_vermelho_L=1;
    wait(0.5);

} 
//Arm and disarm
void Mixer :: arm(){
    armed=true;
    blink_reds();
    //wait(5);
}

void Mixer :: disarm(){
    armed=false;
    motor1=0;
    motor2=0;
    motor3=0;
    motor4=0;

}

//Actuate motors with desired thrust force (N) and torques (N.m)
void Mixer :: actuate(float f_t, float tau_phi, float tau_theta,float tau_psi)
{
    if(armed){
    //led_red_dir=true;
    //led_red_esq=true;
    
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor1= control_motor(omega_1);
    motor2= control_motor(omega_2);
    motor3= control_motor(omega_3);
    motor4= control_motor(omega_4);
    }
    //else{
      //  led_green_dir=true;
        //led_green_esq=true;
    //}
}
//Convert total thrust force (N) and torques (N.m) to angular velocities (rad/s)
void Mixer :: mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
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
//Convert desired angular velocity (rad/s) to PWM signal (%)
float Mixer :: control_motor(float omega_r){
    return omega_r*omega_r*a1+omega_r*a2;
}