#include "holberton1.h"

/**
 * execution - A function which forks a child process and executes a new
 * program within it.
 *
 * @args: A pointer to an array of strings indicating argument values.
 *
 * Return: An integer value indicating success or failure.
 */
int execution(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		//EXECUTE
	}
	else
		wait(&status);
}
