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
	char *command2;
	char **arguments;

	command = interactiveMode();

	arguments = process(command);
	
	if (strcmp(arguments[0], "exit") == 0)
	{
		free(command);
		free(arguments);
		exit(EXIT_SUCCESS);
	}

	free(command2);

	command2 = search_path(arguments[0]);

	if (command2 != NULL)
	{
		free(arguments[0]);
		arguments[0] = command2;
	}

	executeCommand(arguments);

	free(command);
	free(arguments);
}
	return (0);
}
