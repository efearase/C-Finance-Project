#include <cmath>
#include <iostream>

#include "Option.h"
#include "PDECommandCall.h"

const std::string PDECommandCall::getName() const {
  return "Command giving the valuation of a call by Partial Differential "
         "Equtions";
}

const std::string PDECommandCall::getDescription() const {
  return "This command gives the valutation of a call after entering "
         "parameters of option and FDM discretisation parameters by using "
         "the Black Scholes Merton solution by Partial Differential Equtions.";
}
double PDECommandCall::pdecall(double s, double r, double sigma, double k,
                               double T, double x_dom, unsigned long J,
                               double t_dom, unsigned long N) // To complete
{
  return 1;
};

bool PDECommandCall::operator()() {
  Parameters parameters{{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"nb_of_years_before_maturity", ""}};

  PDECommandCall::askParameters(parameters);
  Option option(parameters);

  float s = option.spot_price;
  float r = option.interest_rate;
  float sigma = option.volatility;
  float k = option.strike_price;
  float t = option.nb_of_years_before_maturity;

  std::cout << "The value is " << ' ' << std::endl;
  return true;
}