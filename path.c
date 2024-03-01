/**
  *search_path - search and returns the path for a command
  *@command: this is the command being searched for
  *Return: the path or the executable of the command
  */
#include "main.h"
char *search_path(char *command)
{
	char *path;
	char *token;
	char *full_path;
	char *path_copy;

	path = getenv("PATH");
	path_copy = strdup(path);

	if (path == NULL)
	{
		perror("path");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
