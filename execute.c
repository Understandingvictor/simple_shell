/**
  *executeCommand - executes the command
  *@arguments: parameter
  *Return: 0 on completion
  */

#include "main.h"

int executeCommand(char **arguments)
{
	pid_t pid;
	int status;
	char *path;
	char *path_copy;
	char **envp;

	path = getenv("PATH");
	path_copy = strdup(path);
	envp = malloc(sizeof(char *) + 2);
	envp[0] = path_copy;
	envp[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("pid");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if ((execve(arguments[0], arguments, envp)) == -1)
		{
			perror("excecve");
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
	return (0);
}
