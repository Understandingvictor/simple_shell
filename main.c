/**
  *main - commandline interpreter
  *@ac: arguments counts
  *@ag: argument vector
  *Return: 0 oon success
  */
#include "main.h"
int main(int ac, char *ag[])
{
	(void)ag;
	if (ac == 1)
	{
		interactiveMode();
	}
	else
	{
		dprintf(2, "error in arguments\n");
	}
	return (0);
}
