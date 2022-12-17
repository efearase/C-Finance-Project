#include <iostream>
#include <cmath>

#include "CommandPut.h"
#include "Option.h"


const std::string CommandPut::getName() const
{
  return "Command giving the valuation of a put";
}

const std::string CommandPut::getDescription() const
{
  return "This command gives the valutation of a put after entering parameters like the strike price, the interest rate (...) by using the Black Scholes Merton equation.";
}

float CommandPut::put(float s, float r, float sigma, float k, float t) // To complete
{
  float num = log(s/k)+t*(r+sigma*sigma/2) ;
  float denom = sigma*sqrt(t);
  float d1 = num / denom;
  float d2=d1-denom;
// Here we must find or code a fct to have the pdf of a normal distribution. We put 1 in the meanwhile.
return exp(-r*t)*k*1 - s*1;
};

bool CommandPut::operator()()
{ 
  Parameters parameters {{"spot_price", ""}, {"interest_rate", ""}, {"volatility", ""}, {"strike_price", ""}, {"nb_of_years_before_maturity", ""}};
  
  CommandPut::askParameters(parameters);
  Option option(parameters);

  float s = option.spot_price;
  float r = option.interest_rate;
  float sigma = option.volatility;
  float k = option.strike_price;
  float t = option.nb_of_years_before_maturity;

  std::cout << "The value is " << put(s, r, sigma, k, t) << std::endl;
  return true;
}