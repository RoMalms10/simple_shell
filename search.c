#include "holberton1.h"

/**
  *
  *
  *
  *
  *
  */
char **search(char **args)
{
	extern char **environ;
	char **command;
	char *name = "PATH";
	int x, count;
	char *hold, *cwd;
	struct stat sb;

	/*if (aliases(args) == 0)
	  return (args);
	  if (builtins(args) == 0)
	  return (args);
	  */
	cwd = getcwd(NULL, 0);
	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strcmp(environ[x], name) == 0)
			break;
		else if (environ[x + 1] == NULL)
			perror("Error\n");
	}
	hold = _strdup(environ[x]);
	count = countargs(hold);
	edit_equal_sign(&hold);
	command = parser(hold, count);
	for (x = 0; command[x] != NULL; x++)
	{
		if (chdir(command[x]) == -1)
			perror("Error needs to stop");
		if (stat(args[0], &sb) != -1)
		{
			args[0] = _strconcat(command[x], args[0]);
			break;
		}
	}
	chdir(cwd);
	if (command[x] == NULL)
		perror("Error\n");
	return (args);
}

/**
  *
  *
  *
  *
  */
void edit_equal_sign(char **s)
{
	int x = 0;

	while (s[0][x] != '=')
	{
		s[0][x] = ':';
		x++;
	}
	s[0][x] = ':';
}
