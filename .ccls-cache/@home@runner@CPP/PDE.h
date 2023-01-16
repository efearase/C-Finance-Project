#ifndef __PDE_H
#define __PDE_H

#include "Option.h"

// an abstract base class, providing an interface for all subsequent inherited classes
class ConvectionDiffusionPDE {
 public:
  // PDE Coefficients 
  virtual double diffusion_coefficient(double t, double x) const = 0;
  virtual double convection_coefficient(double t, double x) const = 0;
  virtual double zero_coefficient(double t, double x) const = 0;
  virtual double source_coefficient(double t, double x) const = 0;

  // Boundary and initial conditions
  virtual double bound_l(double t, double x) const = 0;
  virtual double bound_r(double t, double x) const = 0;
  virtual double init_cond(double x) const = 0;
};

// Black-Scholes PDE
class BlackScholes : public ConvectionDiffusionPDE {
 public:
  Option option;
  BlackScholes(Option option);
  
  double diffusion_coefficient(double t, double x) const;
  double convection_coefficient(double t, double x) const;
  double zero_coefficient(double t, double x) const;
  double source_coefficient(double t, double x) const;

  double bound_l(double t, double x) const;
  double bound_r(double t, double x) const;
  double init_cond(double x) const;
};

#endif