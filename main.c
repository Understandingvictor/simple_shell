/**
  *main - commandline interpreter
  *Return: 0 oon success
  */
#include "main.h"
int main(void)
{
while (1)
{
	char *command;
	char **arguments;

	command = interactiveMode();
	arguments = process(command);
	executeCommand(arguments);
}
	return (0);
}
