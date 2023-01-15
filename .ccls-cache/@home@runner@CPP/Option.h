#ifndef OPTION_H
#define OPTION_H

#include "payoff.h"
#include <iostream>
#include <map>
#include <string>

class Option // This class members correspond to options object. 
{
    public:
        PayOff* pay_off;
        Option(std::map<std::string, std::string> parameters);
        double strike_price, volatility, spot_price, interest_rate, nb_of_years_before_maturity;
  
};

#endif