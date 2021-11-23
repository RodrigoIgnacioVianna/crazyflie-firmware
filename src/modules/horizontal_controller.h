#ifndef horizontal_controller_h
#define horizontal_controller_h

#include "mbed.h"
#include "crazyflie.h"

//Horizontal controller class
class HorizontalController
{
 public:
    //Class constructor
    HorizontalController();
    //Control 
    void control(float x_r,float x, float u, float y_r, float y, float v);
    //  theta e phi referernce
    float theta_r, phi_r;

 private:
    //Control 
    float control_siso(float pos_r, float pos , float vel, float kp_hor_c, float kd_hor_c);


};

#endif

