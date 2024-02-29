/**
  *main - this is the program entry
  *Return: 0 upon seuccess
  */
#include "main.h"
int main(void)
{
	char *command = NULL;

	while (1)
	{
		command = read_command();
		execute_command(command);
		free(command);
	}
	return (0);
}
