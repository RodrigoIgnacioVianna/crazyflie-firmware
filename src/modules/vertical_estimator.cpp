#include "vertical_estimator.h"

//Class constructor
VerticalEstimator :: VerticalEstimator() : range(E_SDA,E_SCL)
{
    z=0;
    w=0;

}


//Initialize Class
void VerticalEstimator :: init()
{
    range.init();

}

//Predict vertical position and velocity from model
void VerticalEstimator :: predict(float f_t)
{
    w=w;
    z=z+w*dt_range;

}


//Correct vertical position and velocity with measurement
void VerticalEstimator :: correct(float phi, float theta)
{
    range.read();
    if (range.d<2.0)
    {
        float z_m= range.d*cos(phi)*cos(theta);
        w= w + L1*dt_range*(z_m-z);
        z=z+L2*dt_range*(z_m-z);    
    }   

}

