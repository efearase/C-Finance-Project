#ifndef CONSOLE_H
#define CONSOLE_H

#include <map>
#include <string>
#include <memory>
#include <functional>

#include "Command.h"


class Console
{
private:
	bool end;
	// const Donnees donnees; // Our potential data
	void executeCommand(Command& command);
  std::map<std::string, std::function<void(Console*)> > auxiliary_command;
  std::map<std::string, Command*> pricing_command;
	void quit();
  void help();
  
public:
  Console();
	// Console(const std::string nom_du_fichier); // Here is the function we would use to add a data file.
	void run();
};


#endif