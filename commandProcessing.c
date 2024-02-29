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
		exit(-1);
	}
	
	token = strtok(command, " ");
	while (token != NULL)
	{
		if (i >= 0 && i < 1)
		{
			args[i] = token;
		}
		else
		{
			printf("Error");
			free(args);
			exit(EXIT_FAILURE);
		} 
		token = strtok(NULL, " ");
		i++;
	}	
	args[i] = NULL;
	
	return (args);
}
