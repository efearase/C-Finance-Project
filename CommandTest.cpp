#include <iostream>
#include <string>
#include"CommandTest.h"

const std::string CommandTest::getName() const
{
  return "Test command";
}

const std::string CommandTest::getDescription() const
{
  return "This command helps validate the basic operation of the program.";
}

bool CommandTest::operator()()
{ 
  std::cout << "The command operator() has just been called." << std::endl;

  Parameters parameters {{"param_test", ""}};
  Command::askParameters(parameters);
  if (parameters["param_test"] == "ok")
  {
    std::cout << "The command worked" << std::endl;
  } 
  else
  {
    std::cerr << "The command only works if you enter \"ok\"." << std::endl;
    return false;
  }
  return true;
}