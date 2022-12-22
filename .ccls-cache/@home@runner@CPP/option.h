#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H

#include "payoff.h"

class VanillaOption {
 public:
  PayOff* pay_off;

  double K;
  double r;
  double T;
  double sigma;

  VanillaOption();
  VanillaOption(double _K, double _r, double _T, 
                double _sigma, PayOff* _pay_off);
};

#endif