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
        q_bias+=imu.gy/500.0;
        r_bias+=imu.gz/500.0;
        wait(dt);
    }
    //for(int i=0; i<500; i++)
    //{
      //  imu.read();
        //q_bias+=imu.gy/500.0;
        //wait(dt);
    //}
    //for(int i=0; i<500; i++)
    //{
      //  imu.read();
       // r_bias+=imu.gz/500.0;
        //wait(dt);
    //}
}

//Estimate Euler Angles (rad) and angular velocities (rad/s)
void AttitudeEstimator :: estimate()
{
  imu.read();
  //P, q e r sem os bias
  p=imu.gx-p_bias;
  q=imu.gy-q_bias;
  r=imu.gz-r_bias;
  //phi_a e theta_a
  float phi_a=atan2(-imu.ay,-imu.az);
  float theta_a = atan2(imu.ax, -(((imu.az>0)-(imu.az<0))*(sqrt(imu.ay*imu.ay+imu.az*imu.az))));
  
  //phi_g, theta_g e psi_g

  float phi_g= phi+dt*(p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r);
  float theta_g= theta+dt*(cos(phi)*q-sin(phi)*r);
  float psi_g= psi +dt*(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r);
  
  
  
  
  //phi,theta e psi finais
  phi=(1-alfa)*phi_g+alfa*phi_a;
  theta=(1-alfa)*theta_g+alfa*theta_a;
  psi=psi_g;

  
 


}