#include <iostream>

#include "Command.h"

/*
This function takes as argument a collection of parameters whose names we know
but not yet the values (or only the default values). It prompts the user for the
value of each parameter.
 */
void Command::askParameters(Command::Parameters &parameters) const {
  for (auto p = parameters.begin(); p != parameters.end(); p++) {
    std::cout << "Enter the " << p->first << ", please : \n"
              << "> ";
    std::string parameter;
    std::getline(std::cin, parameter);
    p->second = parameter;
  }
}

std::ostream &operator<<(std::ostream &os, const Command &cmd) {
  os << cmd.getName() << "\n" << cmd.getDescription() << "\n";
  return os;
}