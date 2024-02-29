/**
 *interactiveMode - This executes code in interactive mode
 *Return: 0 upon completion
 */
#include "main.h"
char *interactiveMode(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(fileno(stdin)))
	{
		printf("#cisfun$ ");
		fflush(stdout);
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			free(command);
			perror("isatty read");
			exit(EXIT_FAILURE);
		}
		if (read > 1)
		{
			command[strcspn(command, "\n")] = '\0';
			return (command);
		}
	}
	else
	{
		printf("#cisfun$ ");
		read = getline(&command, &len, stdin);
		if (read == -1)
		{
			free(command);
			perror("!isatty read");
			exit(EXIT_FAILURE);
		}
		if (read > 1)
		{
			command[strcspn(command, "\n")] = '\0';
			return (command);
		}
	}
return (NULL);
}
