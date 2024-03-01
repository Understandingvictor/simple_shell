/**
 *process - processes command
 *@command: command to be processed
 *Return: nothing
 */
#include "main.h"
char **process(char *command)
{
	char *token;
	char **args;
	int i = 0;

	args = malloc(sizeof(char *) * buffersize);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = strdup(token);

		if (args[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	return (args);
}
