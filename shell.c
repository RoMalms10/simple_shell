#include "holberton1.h"

/**
  * main - Entry Point
  * Creates a loop that counts how many times it has gone through the loop
  * Calls functions
  * @argc: argument count
  * @argv: an array of pointers to chars, arguments
  * @env: the environment
  * Return: 0, success, otherwise the child exits the functions on errors
  */
int main(int argc, __attribute__((unused))char **argv, __attribute__((unused))char **env)
{
	int loops, status, count;
	char *line = NULL;
	char **args = NULL;
	size_t n = 0;
	pid_t my_pid;

	if (argc > 1)
	{
		;/*do something with argv*/
	}
	for (loops = 1; 1; loops++)
	{
		printf("$ ");
		getline(&line, &n, stdin);
		my_pid = fork();
		if (my_pid == 0)
		{
			count = countargs(line);
			args = parser(line, count);
			interpreter(args);
		}
		else if (my_pid == -1)
		{
			/*error*/
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
