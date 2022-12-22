#include <cmath>
#include <iostream>

#include "PDECommandCall.h"
#include "Option.h"
#include "PDEparams.h"

const std::string PDECommandCall::getName() const {
  return "Command giving the valuation of a call by Partial Differential Equtions";
}

const std::string PDECommandCall::getDescription() const {
  return "This command gives the valutation of a call after entering "
         "parameters of option and FDM discretisation parameters by using "
         "the Black Scholes Merton solution by Partial Differential Equtions.";
}
double PDECommandCall::pdecall(double s, double r, double sigma, double k,
                        double T, double x_dom, unsigned long J , double t_dom,  unsigned long N ) // To complete
{
  return 0.0;
};

bool PDECommandCall::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"nb_of_years_before_maturity", ""},
                        {"x_dom", ""},
                        {"J", ""},
                        {"N", ""}};

  PDECommandCall::askParameters(parameters);
  Option option(parameters);

  double s = option.spot_price;
  double r = option.interest_rate;
  double sigma = option.volatility;
  double k = option.strike_price;
  double t = option.nb_of_years_before_maturity;
  pde_params pde_params(parameters);
  // FDM discretisation parameters
  double x_dom = pde_params.x_dom;       // Spot goes from [0.0, 1.0]
  double J = pde_params.J; 
  double t_dom = t;         // Time period as for the option
  double N = pde_params.N; 

  std::cout << "The value is " <<  0  << std::endl;
  return true;
}