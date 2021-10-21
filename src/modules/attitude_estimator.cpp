#include "attitude_estimator.h"

//Class constructor 
AttitudeEstimator :: AttitudeEstimator() : imu(IMU_SDA,IMU_SCL)
{
    phi=0;
    theta=0;
    psi=0;
    p=0;
    q=0;
    r=0;
} 

//Initialize class
void AttitudeEstimator :: init()
{
    imu.init();
    for(int i=0; i<500; i++)
    {
        imu.read();
        p_bias+=imu.gx/500.0;
        wait(dt);
    }
}

//Estimate Euler Angles (rad) and angular velocities (rad/s)
void AttitudeEstimator :: estimate()
{
  imu.read();
  p=imu.gx-p_bias;
  float phi_g= phi+p*dt;
  phi=phi_g;
  //float phi_a=atan2(-imu.ay,-imu.az);
 // phi=alfa*phi_a+(1-alfa)*phi;


}