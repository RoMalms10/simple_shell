#include "holberton1.h"

/**
  * exit_function - exits the shell
  * leave this spot open for arguments when taking options
  * Return: 0 on success, will never make it there
  */
int exit_function(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

/**
  * print_env - prints the environment
  * Return: 0 on success
  */
int print_env(void)
{
	extern char **environ;
	int x;

	for (x = 0; environ[x] != NULL; x++)
		printf("%s\n", environ[x]);
	return (0);
}
