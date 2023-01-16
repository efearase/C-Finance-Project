#ifndef __PDE_CPP
#define __PDE_CPP

#include "PDE.h"
#include <math.h>

BlackScholes::BlackScholes(Option option) : option(option) {}

// Diffusion coefficient
// x is the spot price
double BlackScholes::diffusion_coefficient(double t, double x) const {
  double sigma = option.volatility;
  return sigma*sigma*x*x/2; }

// Convection coefficient
double BlackScholes::convection_coefficient(double t, double x) const {
  return (option.interest_rate)*x; }
// Zero-term coefficient
double BlackScholes::zero_coefficient(double t, double x) const {
  return -(option.interest_rate);}

// Source coefficient
double BlackScholes::source_coefficient(double t, double x) const {
  return 0;}

// Left boundary-condition
double BlackScholes::bound_l(double t, double x) const {
  if (option.type==1)
    return 0; // for call
  else return (option.strike_price) * exp(-(option.interest_rate) * (-option.nb_of_years_before_maturity+t)); } // for put

// Right boundary-condition 
double BlackScholes::bound_r(double t, double x) const {
  // Using call-put parity
  if (option.type == 1)
    return (x-(option.strike_price)*exp(-(option.interest_rate)*    (-option.nb_of_years_before_maturity+t))); // for call
  else return 0;} //for put

// Initial condition
double BlackScholes::init_cond(double x) const {
  return option.pay_off->operator()(x);}

#endif