/**
 *process - processes command
 *@command: command to be processed
 *Return: nothing
 */
#include "main.h"
void process(char *command)
{
	char *token;
	char **args;
	int status;
	pid_t pid;

	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	token = strtok(command, " ");
	args[0] = token;	
	args[1] = NULL;

	pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	if (pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
			dprintf(2, "./shell: No such file or directory\n");
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}
}
