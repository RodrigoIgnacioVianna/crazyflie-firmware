#include "horizontal_controller.h"

//Class constructor
HorizontalController :: HorizontalController() 
{
    phi_r=0;
    theta_r=0;

}   

//Control reference roll and pitch angles ( rad ) given reference positions (m) and current positions (m) and velocities (m/s)
void HorizontalController :: control(float x_r,float y_r, float x, float y, float u, float v)
{
    phi_r=(-1.0/g)*control_siso(y_r,y,v,kp_hor,kd_hor);
    theta_r=(1.0/g)*control_siso(x_r,x,u,kp_hor,kd_hor);

    
}

//Control acceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float HorizontalController :: control_siso(float pos_r, float pos , float vel, float kp_hor_c, float kd_hor_c)
{
    return kp_hor_c*(pos_r-pos)+kd_hor_c*(-vel);

}