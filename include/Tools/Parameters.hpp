#pragma once

#include "math.hpp"

typedef struct Parameters
{
	Real Adam_beta1 = 0.5, Adam_beta2 = 0.51, Adam_gamma = 0.337;
	Real AdamW_beta1 = 0.5, AdamW_beta2 = 0.97, AdamW_gamma = 0.2;
	Real RmsProp_beta = 0.5, RmsProp_alpha = 0.66;
	Real Adagrad_beta = 0.99;
	Real AdaMax_beta1 = 0.5, AdaMax_beta2 = 0.56, AdaMax_gamma = 0.337;
	Real Adadelta_beta = 0.6;
	Real Nadam_beta1 = 0.96, Nadam_beta2 = 0.98, Nadam_gamma = 0.4;
	Real AMSGrad_beta1 = 0.84, AMSGrad_beta2 = 0.74, AMSGrad_gamma = 1.15;
	Real Nesterov_ro = 2.0, Nesterov_teta = 1.1, Nesterov_alfa = 1.0;
	
	/*
	old
	Real Adam_beta1 = 0.86296943, Adam_beta2 = 0.88791641, Adam_gamma = 0.07670128;
	Real RmsProp_beta = 0.93005474, RmsProp_alpha = 0.06376147;
	Real Adagrad_beta = 1.0;
	Real AdaMax_beta1 = 0.92096770, AdaMax_beta2 = 0.95563197, AdaMax_gamma = 0.18211471;
	Real Adadelta_beta = 0.999;
	Real Nadam_beta1 = 0.88441989, Nadam_beta2 = 0.88441989, Nadam_gamma = 0.08381000;
	Real AMSGrad_beta1 = 0.86296943, AMSGrad_beta2 = 0.88791641, AMSGrad_gamma = 0.07670128;
	Real Nesterov_ro = 2.0, Nesterov_teta = 1.1, Nesterov_alfa = 1.0;
	*/
} Params;

