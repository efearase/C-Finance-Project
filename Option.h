#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <map>
#include <string>
#include "payoff.h"

class Option // This class members correspond to options object. 
{
    public:
        Option(std::map<std::string, std::string> parameters);

        PayOff* pay_off;
        double strike_price, volatility, spot_price, interest_rate, nb_of_years_before_maturity, x_dom, J, N, T;
};

#endif