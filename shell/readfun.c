/**
  *read_command - reads command input and removes \n character
  *Return: nothing
  */
#include "main.h"

char *read_command(void)
{
	char *command = NULL;
	size_t buffer_size = 0;
	ssize_t input_length;

	if (!isatty(fileno(stdin)))
	{
		input_length = getline(&command, &buffer_size, stdin);
		if (input_length == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("#cisfun$ ");
		fflush(stdout);
		input_length = getline(&command, &buffer_size, stdin);
		if (input_length == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
	}
	command[strcspn(command, "\n")] = '\0';
	return (command);
}
