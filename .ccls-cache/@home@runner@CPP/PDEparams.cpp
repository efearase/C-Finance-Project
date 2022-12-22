#include <iostream>
#include <cmath>
#include "PDEparams.h"

pde_params::pde_params(std::map<std::string, std::string> parameters){
  x_dom = std::stof(parameters["x_dom"]);
  J = std::stof(parameters["J"]);
  N = std::stof(parameters["N"]);
}