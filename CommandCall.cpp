#include <iostream>
#include <cmath>

#include "CommandCall.h"
#include "Option.h"


const std::string CommandCall::getName() const
{
  return "Command giving the valuation of a call";
}

const std::string CommandCall::getDescription() const
{
  return "This command gives the valutation of a call after entering parameters like the strike price, the interest rate (...) by using the Black Scholes Merton equation.";
}

bool CommandCall::operator()()
{ 
  Parameters parameters {{"spot_price", ""}, {"interest_rate", ""}, {"volatility", ""}, {"strike_price", ""}, {"nb_of_years_before_maturity", ""}};
  
  CommandCall::askParameters(parameters);
  Option option(parameters);

  float s = option.spot_price;
  float r = option.interest_rate;
  float sigma = option.volatility;
  float k = option.strike_price;
  float t = option.nb_of_years_before_maturity;

  std::cout << "The value is " << std::endl;
  return true;
}