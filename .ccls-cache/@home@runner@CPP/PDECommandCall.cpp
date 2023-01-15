#include <cmath>
#include <iostream>

//#include <Python.h>
#include "PDECommandCall.h"
#include "Option.h"
#include "PDEparams.h"
#include "payoff.h"
#include "option.h"
#include "pde.h"
#include "fdm.h"

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
  // Create the PayOff and Option objects
  PayOff* pay_off_call = new PayOffCall(k);
  VanillaOption* call_option = new VanillaOption(k, r, T, sigma, pay_off_call);

  // Create the PDE and FDM objects
  BlackScholesPDE* bs_pde = new BlackScholesPDE(call_option);
  FDMEulerExplicit fdm_euler(x_dom, J, t_dom, N, bs_pde);

  // Run the FDM solver
  fdm_euler.step_march();

  // Delete the PDE, PayOff and Option objects
  delete bs_pde;
  delete call_option;
  delete pay_off_call;

  // Executing python file for data visualisation
  //char filename[] = "pyemb7.py";
	//FILE* fp;

	//Py_Initialize();

	//fp = _Py_fopen(filename, "r");
	//PyRun_SimpleFile(fp, filename);

	//Py_Finalize();
  return 0;
};

bool PDECommandCall::operator()() {
  Parameters parameters{//{"spot_price", ""},
                        {"interest_rate", ""},
                        {"volatility", ""},
                        {"strike_price", ""},
                        {"nb_of_years_before_maturity", ""},
                        {"x_dom", ""},
                        {"J", ""},
                        {"N", ""}};

  PDECommandCall::askParameters(parameters);
  Option option(parameters);

 // double s = option.spot_price;
  double r = option.interest_rate;
  double sigma = option.volatility;
  double k = option.strike_price;
  double t = option.nb_of_years_before_maturity;
  pde_params pde_params(parameters);
  // FDM discretisation parameters
  double x_dom = pde_params.x_dom;       // Spot goes from [0.0, x_dom]
  double J = pde_params.J;         // Number of spatial differencing points
  double t_dom = t;         // Time period as for the option
  double N = pde_params.N;       // Number of temporal differencing points

  std::cout << "The value is " <<  pdecall(s, r, sigma,  k, t, x_dom, J , t_dom,  N )   << std::endl;
  return true;
}