#include "holberton1.h"

/**
  * find_path - finds the PATH variable in the environment
  * @name: the name to look for - "PATH"
  * Return: the string containing the whole PATH variable
  */
char *find_path(char *name)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strcmp(environ[x], name) == 0)
			break;
		else if (environ[x + 1] == NULL)
			perror("find path");
	}
	return (environ[x]);
}
