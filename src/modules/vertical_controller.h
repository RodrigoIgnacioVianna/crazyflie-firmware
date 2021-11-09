#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "crazyflie.h"

//Attitude controller class
class VerticalController
{
 public:
    //Class constructor
    VerticalController();
    //Control z (m) given reference z (rad) and current velocity (m/s)
    void control(float z_r, float z, float w);
    // z reference, reference, force
    float z_r, z, w, f_t;
 private:
    //Controll torque (N.m) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
    float control_siso(float dist_r, float dist , float vel, float kp_ver_c, float kd_ver_c);

};

#endif

