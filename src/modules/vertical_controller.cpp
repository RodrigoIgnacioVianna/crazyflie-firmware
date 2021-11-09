#include "vertical_controller.h"

//Class constructor
VerticalController :: VerticalController() : range(E_SDA,E_SCL)
{
    z=0;
    w=0;

    
    

}   

//Control torques (N.m) given reference angles (rad) and current angles (rad) and angular velocities (rad/s)
void VerticalController :: control(float z_r, float z, float w);
{
    tau_phi= I_xx*control_siso(phi_r, phi,p,kp_att, kd_att);
    tau_theta= I_yy*control_siso(theta_r, theta,q,kp_att, kd_att);
    tau_psi= I_zz*control_siso(psi_r, psi,r,kp_att, kd_att);
    

}

//Control torques (N.m) given reference angle (rad) and current angle (rad) and angular velocities (rad/s) with given controller gains
float VerticalController :: control_siso(float dist_r, float dist , float vel, float kp_ver_c, float kd_ver_c);
{
    return kp_c*(angle_r-angle)+kd_c*(-rate);

}