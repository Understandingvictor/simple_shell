/**
  *execute_command - executes command received
  *@command: command received
  *Return: noting on completion
  */
#include "main.h"
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *token;
	char **argv;

	token = strtok(command, " ");
	argv = malloc(2 * sizeof(char *));
	if  (argv == NULL)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	argv[0] = token;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	free(argv);
}
