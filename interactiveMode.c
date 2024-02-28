/**
 *interactiveMode - This executes code in interactive mode
 *Return: 0 upon completion
 */
#include "main.h"
void interactiveMode(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(fileno(stdin)))
	{
		while (1)
		{
			printf("#cisfun$ ");
			read = getline(&command, &len, stdin);
			if (read == -1)
			{
				return;
			}
			if (read > 1)
			{
				command[strcspn(command, "\n")] = '\0';
				process(command);
			}
		}
	free(command);
	}
	else
	{
		printf("#cisfun$ ");
		read = getline(&command, &len, stdin);
		if (read == -1)
			return;
		if (read > 1)
		{
			command[strcspn(command, "\n")] = '\0';
			process(command);
		}
	}
}
