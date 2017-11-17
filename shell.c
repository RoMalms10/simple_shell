#include "holberton1.h"

/**
  * main - Entry Point
  * Creates a loop that counts how many times it has gone through the loop
  * Calls functions
  * @argc: argument count
  * @argv: an array of pointers to chars, arguments
  * Return: 0, success, otherwise the child exits the functions on errors
  */
int main(void)
{
	int loops, count;
	char *line;
	char **args;
	size_t n;

	signal(SIGINT, SIG_IGN);
	for (loops = 1; 1; loops++)
	{
		line = NULL;
		n = 0;
		args = NULL;
		printf("$ ");
		if (getline(&line, &n, stdin) == EOF)
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		count = countargs(line);
		args = parser(line, count);
		interpreter(args);
		free(line);
		free(args);
	}
	return (0);
}
