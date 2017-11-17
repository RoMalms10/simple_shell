#include "holberton1.h"

/**
  * exit_function - exits the shell
  *
  *
  */
int exit_function(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

/**
  * print_env - prints the environment
  *
  *
  */
int print_env(void)
{
	extern char **environ;
	int x;

	for (x = 0; environ[x] != NULL; x++)
		printf("%s\n", environ[x]);
	return (0);
}
