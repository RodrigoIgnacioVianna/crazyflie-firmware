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
const float wc=1.2; //rad/s
const float wc_ver=10;//frequência de corte estimador vertical
const float dt=0.002;//s
const float dt_range=0.05;//s
const float alfa = (wc*dt)/(1.0+wc*dt);

const float zeta_ver=sqrt(2.0)/2.0;
const float L1= wc_ver*wc_ver;
const float L2= 2.0*zeta_ver*wc_ver;

const float OS_att=0.005;
const float TS_att= 0.3; //s

const float zetta_att = abs(log(OS_att))/sqrt(pi*pi+log(OS_att)*log(OS_att));
const float wn_att = 4.0/(TS_att*zetta_att);
const float kp_att=wn_att*wn_att;
const float kd_att=2.0*zetta_att*wn_att;

const float TS_att_psi= 0.6; //s

const float wn_att_psi = 4.0/(TS_att_psi*zetta_att);
const float kp_att_psi=wn_att_psi*wn_att_psi;
const float kd_att_psi=2.0*zetta_att*wn_att_psi;



const float OS_ver=0.005;
const float TS_ver= 2.0; //s
const float zetta_ver = abs(log(OS_ver))/sqrt(pi*pi+log(OS_ver)*log(OS_ver));
const float wn_ver = 4.0/(TS_ver*zetta_ver);
const float kp_ver=wn_ver*wn_ver;
const float kd_ver=2.0*zetta_ver*wn_ver;


const float W=420;//pixels
const float gama= (2*pi/180)*42;//rad
const float sigma= (2*tan(gama/2))/(W*dt);


const float L_hor=50;

//cálculo ganhos controlador horizontal
const float OS_hor=0.005;
const float TS_hor= 2.0; //s
const float zetta_hor = abs(log(OS_hor))/sqrt(pi*pi+log(OS_hor)*log(OS_hor));
const float wn_hor = 4.0/(TS_hor*zetta_hor);
const float kp_hor=wn_hor*wn_hor;
const float kd_hor=2.0*zetta_hor*wn_hor;








#endif