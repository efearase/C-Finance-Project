#include <iostream>
#include <stdlib.h> 

#include "Console.h"
#include "Command.h"
#include "CommandTest.h"
#include "CommandPut.h"

Console::Console() // or "Console(const std::string file_name)" if we have data, with the following: "data{Data(file_name)}" if we add a class named Data
{
  std::function <void(Console*)> command_quit = &Console::quit;
  std::function <void(Console*)> command_help = &Console::help;
  
  auxiliary_command["quit"] = command_quit;
  auxiliary_command["help"] = command_help;

  CommandTest* command_test = new CommandTest;
  CommandPut* command_put = new CommandPut;
  // We could use smart pointers here to avoid having to deal with the use of delete.
  
  pricing_command["test"] = command_test;
  pricing_command["put"] = command_put;
}


void Console::run()
{
	end = false;
	// Test if the user asked to quit (or if the program is tired of working).
	while (!end)
	{
    std::cout << "\nCommands:\n\n quit\n help\n test\n put\n\n";
		// We display a request (a "prompt") a command to the user:
		std::cout << "Enter your command: \n"
			  << "> ";
		// Command recovery:
		std::string command;
		std::getline(std::cin, command);

		// This test is used to check if the input is a mistake (like if the user has typed "enter", for instance):
		if (!std::cin)
			break;

    std::map<std::string, Command*>::iterator cmd = pricing_command.find(command); 
    if (cmd == pricing_command.end())
    {
      std::map<std::string,std::function<void(Console*)>>::iterator cmd2 = auxiliary_command.find(command);
      if (cmd2 == auxiliary_command.end())
      {
        std::cout << "This command does not exist." << std::endl;
      }
      else 
      {
        auto fonction_command = auxiliary_command[command];
      fonction_command(this);
      }
    }
    else 
    {
      executeCommand(*pricing_command[command]);
    }
	}
  delete pricing_command["test"];
  delete pricing_command["put"];
  // As we use dynamic allocation, you have to think about freeing the memory space "manually".
  exit(0);
}


void Console::executeCommand(Command& command)
{
  std::cout << "\n Command name: " << command.getName() << "\n\n Command description: " << command.getDescription() << std::endl;

  bool resultat = command(); // Or "command(data);" if we use data
  if(resultat == false)
  {
    std::cerr << "The command encountered an error during execution." << std::endl;
  } 
}


void Console::quit()
{
	std::cout << "Thank you for using our pricing program!" << std::endl;
	end = true;
}


void Console::help()
{
  std::cout << "\nHello, this pricing program responds to different commands that you can enter manually.\nBelow you will find the list of available commands, followed by their name to use them and by a short description:\n\n" << std::endl;

  for (std::pair <std::string , Command*> command : pricing_command)
  {
    std::cout << "\n " << command.second -> getName() << "\n " << "Name: " << command.first << "\n " << command.second -> getDescription() << "\n" << std::endl;
  }
  std::cout << "\n \n You also have the following auxiliary commands which participate in the operation of the program and which work as their (recognized) name indicates:" << std::endl;

  for (std::pair <std::string, std::function<void(Console*)> > command : auxiliary_command)
  {
    std::cout << "\n " << command.first << "\n" << std::endl;
  }
}