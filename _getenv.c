#include "holberton1.h"

/**
 * _getenv - Searches the environment list for variable name
 *
 * @name: A pointer to a contant string.
 *
 * Return: A pointer to a string.
 */
char *_getenv(const char *name)
{
	char *address;
	size_t len, env_list, letter, i;

	for (len = 0; name[len] != '\0';)
		len++;

	env_list = letter = 0;
	while (environ[env_list] != NULL)
	{
		if (environ[env_list][0] == name[letter])
		{
			address = environ[env_list];
			i = 0;
			while (name[letter] != '\0' && environ[env_list][i] == name[letter])
			{
				i++;
				letter++;
				if (letter == len)
					return (address);
				else if (environ[env_list][i] != name[letter])
					letter = 0;
			}
		}
		env_list++;
	}
	return (NULL);
}
