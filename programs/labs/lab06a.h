#include "mbed.h"
#include "crazyflie.h"

//Declare Mixer
Mixer mixer;
//Main program
int main(){
    //Actuate motor with 70%mg total thrust force and zero torques
    mixer.actuate(0,0,0,-0.001);
    wait(5);
    //Turn off motors
    mixer.actuate(0,0,0,0);
    //End program
    while(true){

    }
}