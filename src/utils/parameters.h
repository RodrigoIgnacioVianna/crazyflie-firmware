#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

const float a2 = 2.802e-12;
const float a1 = 1.16e-7;
const float kl= 1.589e-8;
const float kd= 1.322e-10;
const float wc=1; //rad/s
const float delta_t=0.1;
const float alfa = (wc*delta_t)/(1+wc*delta_t)
#endif