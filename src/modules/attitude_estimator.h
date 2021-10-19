#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

//Attitude estimator class
class AttitudeEstimator 
{
    public:
        //Class constructor
        AttitudeEstimator();
        //Initialize Class
        void init();
        //Estimate Euler Angles (rad) and angular velocities (rad/s)
        void estimate();
        // Euler angles (rad)
        float phi, theta, psi;
        //Angular velocities (rad/s)
        float p, q, r;
    private:
        //IMU SENSOR   OBJECT
        BMI088 imu;
    
};

#endif

