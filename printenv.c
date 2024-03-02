/**
  *printenv - prints the environment of current process
  *Return: nothing
  */
#include "main.h"
void printenv()
{
	extern char **environ;
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
