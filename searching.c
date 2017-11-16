#include "holberton.h"

/**
 * search - Interprets first argument from command line and searches for it in
 * either path or array of built-ins.
 *
 * @name: a pointer to a string
 *
 * Return: A pointer to a directory
 */
char **search(const char *name)
{
	char *location;
	int len, path_i, letter, i;

	len = _strlen(name);
	while (environ[path_i] != NULL)
}
