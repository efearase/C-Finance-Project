#ifndef __PDE_CPP
#define __PDE_CPP

#include "pde.h"
#include <math.h>

BlackScholesPDE::BlackScholesPDE(Option option) : option(option) {}

// Diffusion coefficient
// x is the spot price
double BlackScholesPDE::diff_coeff(double t, double x) const {
  double vol = option.volatility;
  return 0.5*vol*vol*x*x;  // \frac{1}{2} \sigma^2 S^2
}

// Convection coefficient
double BlackScholesPDE::conv_coeff(double t, double x) const {
  return (option.interest_rate)*x;  // rS
}

// Zero-term coefficient
double BlackScholesPDE::zero_coeff(double t, double x) const {
  return -(option.interest_rate);  // -r
}

// Source coefficient
double BlackScholesPDE::source_coeff(double t, double x) const {
  return 0.0;
}

// Left boundary-condition (vanilla call option)
double BlackScholesPDE::boundary_left(double t, double x) const {
  return 0.0;  // Specifically for a CALL option
}

// Right boundary-condition (vanilla call option)
double BlackScholesPDE::boundary_right(double t, double x) const {
  // This is via Put-Call Parity and works for a call option
  return (x-(option.strike_price)*exp(-(option.interest_rate)*((option.nb_of_years_before_maturity)-t))); 
}

// Initial condition (vanilla call option)
double BlackScholesPDE::init_cond(double x) const {
  return option.pay_off->operator()(x);
}

#endif