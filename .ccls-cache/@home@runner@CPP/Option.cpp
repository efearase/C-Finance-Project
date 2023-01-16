#include <iostream>
#include <cmath>
#include "Option.h"

Option::Option(std::map<std::string, std::string> parameters){
  spot_price = std::stof(parameters["spot_price"]);
  interest_rate = std::stof(parameters["interest_rate"]);
  volatility = std::stof(parameters["volatility"]);
  strike_price = std::stof(parameters["strike_price"]);
  nb_of_years_before_maturity = std::stof(parameters["nb_of_years_before_maturity"]);
  pay_off = 0;
  type = 1;
}