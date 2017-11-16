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
	char **command;
	extern char **environ;
	char *name = "PATH";
	int x;
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
		{
			/*error*/
		}
	}
	printf("%s\n", environ[x]);
	hold = _strdup(environ[x]);
	edit_equal_sign(&hold);
	command = parser(hold, countargs(hold));
	for (x = 0; command[x] != NULL; x++)
	{
		if (chdir(command[x]) == -1)
		{
			/*error*/
		}
		if (stat(args[0], &sb) == 0)
		{
			args[0] = _strconcat(command[x], args[0]);
			break;
		}
	}
	chdir(cwd);
	if (command[x] == NULL)
	{
		/*error*/
	}
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
		s[0][x] = '\0';
		x++;
	}
	s[0][x] = '\0';
}
