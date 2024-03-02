/**
  *printenv - prints the environment of current process
  *Return: nothing
  */
#include "main.h"
void printenv()
{
	char *env_var;
	int i;

	for (i = 0; ; i++)
	{
		env_var = getenv("environ");
		if (env_var == NULL)
		{
			break;
		}
		printf("%s\n", env_var);
	}
}
