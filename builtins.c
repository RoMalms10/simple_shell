#include "holberton1.h"

/**
  * exit_function - exits the shell
  * leave this spot open for arguments when taking options
  * Return: 0 on success, will never make it there
  */
int exit_function(char **args, char *line)
{
	int number;

	if (args[1] != NULL)
		number = _atoi(args[1]);
	if (number == -1)
	{
		return (0);
	}
	else
	{
		free_function(1, line);
		free_function(2, args);
		exit(number);
	}
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
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
