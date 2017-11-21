#include "holberton1.h"

/**
  * exit_function - exits the shell
  * @args: the arguments getting passed to exit
  * args[1] will be the number to exit with
  * @line: a malloc'd space that needs to be freed before exit
  * Return: 0 on success, will never make it there
  */
int exit_function(char **args, char *line)
{
	int number;

	number = 0;
	if (args[1] != NULL)
		number = _atoi(args[1]);
	if (number == -1)
	{
		return (-1);
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
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
  * _sigign - checks if the signal was SIGINT, then prints a \n and the prompt
  * @sig: the number of the signal
  * Return: nothing, void
  */
void _sigign(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
