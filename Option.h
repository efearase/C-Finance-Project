#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <map>
#include <string>

class Option // This class members correspond to options object. 
{
    public:
        Option(std::map<std::string, std::string> parameters);

        float strike_price, volatility, spot_price, interest_rate, nb_of_years_before_maturity;
};

#endif