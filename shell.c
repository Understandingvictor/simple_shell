#include "main.h"
#define buffersize 1024
/**
  *process - processes command
  *@command: command to be processed
  *Return: nothing
  */
void process(char *command)
{
	char *token;
	char *args[buffersize];
	int i = 0;
	int status, returned;
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
			dprintf(2, "shell: 1: %s: not found\n", args[0]);
	}
	else
	{
		wait(&status);
	}
}


/**
  *interactiveMode - This executes code in interactive mode
  *Return: 0 upon completion
  */
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


/**
  *nonInteractiveMode - works uninteractively
  *@filename: file to work on
  *Return: nothing
  */
void nonInteractiveMode(char *filename)
{
	char *command = NULL;
	size_t len = 0;
	FILE *ptr;

	ptr = fopen(filename, "r");

	if (ptr == NULL)
	{
		perror("error reading file");
		exit(EXIT_FAILURE);
	}

	while ((getline(&command, &len, ptr)) != -1)
	{
		command[strcspn(command, "\n")] = '\0';
		printf("%s\n", command);
		process(command);
		free(command);
		command = NULL;
	}
	fclose(ptr);
}


/**
  *main - commandline interpreter
  *@ac: arguments count
  *@ag: argument vector
  *Return: 1 on success
  */
void main(int ac, char *ag[])
{
	if (ac == 1)
	{

		interactiveMode();
	}
	else if (ac == 2)
	{
		nonInteractiveMode(ag[1]);
	}
	else
	{
		dprintf(2, "error in arguments\n");
	}
}
