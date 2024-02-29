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
	int status;
	pid_t pid;

	token = strtok(command, " ");
	args[0] = token;	
	args[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if ((execve(args[0], args, NULL)) == -1)
			dprintf(2, "./shell: No such file or directory\n");
	}
	else
	{
		wait(&status);
	}
}
