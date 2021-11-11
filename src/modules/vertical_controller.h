#ifndef vertical_controller_h
#define vertical_controller_h

#include "mbed.h"
#include "crazyflie.h"

//Vertical controller class
class VerticalController
{
 public:
    //Class constructor
    VerticalController();
    //Control total thrust force (N) given reference vertical position (m) and current vertical position (m) and velocity (m/s)
    void control(float z_r, float z, float w);
    //  total thrust force (N)
    float f_t;
 private:
    //Control aceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gain
    float control_siso(float pos_r, float pos , float vel, float kp_ver_c, float kd_ver_c);

};

#endif

