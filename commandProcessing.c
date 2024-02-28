/**
 *process - processes command
 *@command: command to be processed
 *Return: nothing
 */
#include "main.h"
void process(char *command)
{
	char *token;
	char *args[buffersize];
	int i = 0;
	int status;
	pid_t pid;

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	if (i > 1)
	{
		printf("No such file or directory\n");
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
			dprintf(2, "shell: 1; %s: not found\n", args[0]);
	}
	else
	{
		wait(&status);
	}
}
