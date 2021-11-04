#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.0 hardware abstraction layer
//#include "drivers/mpu9250.h"    // IMU sensor

// Flow deck hardware abstraction layer
//#include "drivers/vl53l0x.h"    // Range sensor
//#include "drivers/pmw3901.h"    // Optical flow sensor

//incluir mixer.h
#include "modules/mixer.h"

// Crazyflie 2.1 hardware abstraction layer
 #include "drivers/bmi088.h"     // IMU sensor
 //incluir estimador ded attitude
 #include "modules/attitude_estimator.h"
 #include "modules/attitude_controller.h"


// Flow deck v2 hardware abstraction layer
 #include "drivers/vl53l1x.h"    // Range sensor
 #include "drivers/pmw3901.h"    // Optical flow sensor

#endif