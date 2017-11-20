#include "holberton1.h"

/**
  *
  *
  *
  */
char *find_path(char *name)
{
	int x;
	extern char **environ;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strcmp(environ[x], name) == 0)
			break;
		else if (environ[x + 1] == NULL)
			perror("find path");
	}
	return (environ[x]);
}
