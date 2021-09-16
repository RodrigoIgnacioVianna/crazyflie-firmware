#include "mbed.h"
#include "crazyflie.h"

//Declare Mixer
Mixer mixer;
//Main program
int main(){
    //Arm mixer
    //mixer.arm();
    //Actuate motor with 70%mg total thrust force and zero torques
    mixer.actuate(0,0,0,-0.001);
    wait(5);
    //Disarm mixer
    mixer.disarm();
    //End program
    while(true){

    }
}