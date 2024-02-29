/**
  *executeCommand - executes the command
  *@arguments
  *Return: 0 on completion
  */

#include "main.h"

void executeCommand(char **arguments)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if ((execve(arguments[0], arguments, NULL)) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if ((waitpid(pid, &status, 0)) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
