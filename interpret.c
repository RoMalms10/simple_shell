#include "holberton1.h"

/**
 * interpreter - checks args[0] to see whether or not it needs to search
 * for a command in the PATH
 * @args: arguments to pass to execution
 * Return: nothing, void
 */
void interpreter(char **args)
{
	struct stat sb;

	if (stat(args[0], &sb) == -1)
		search(args);
	execution(args);
}
