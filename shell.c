#include "holberton1.h"

/**
  * main - Entry Point
  * Creates a loop that counts how many times it has gone through the loop
  * Calls functions
  * @argc: argument count
  * @argv: an array of pointers to chars, arguments
  * Return: 0, success, otherwise the child exits the functions on errors
  */
int main(__attribute__((unused)) int argc, char **argv)
{
	int loops, count;
	char *line;
	char **args;
	size_t n;

	signal(SIGINT, _sigign);
	for (loops = 1; 1; loops++)
	{
		line = NULL;
		n = 0;
		args = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		if (getline(&line, &n, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		count = countargs(line);
		args = parser(line, count);
		if (_strcmp(args[0], "exit") == 0 &&
				(_strlen(args[0]) == _strlen("exit")))
		{
			if (exit_function(args, line) == -1)
				err_mess(argv, args, loops);
		}
		else if (args != NULL && args[0] != NULL)
		{
			if (interpreter(args) == -1)
				err_mess(argv, args, loops);
		}
		free_function(1, line);
		free_function(2, args);
	}
	return (0);
}
