#include "holberton1.h"

/**
  *
  *
  *
  *
  *
  */
int search(char **args)
{
	extern char **environ;
	char **command;
	char *name = "PATH";
	int x, count;
	char *hold, *cwd;
	struct stat sb;

	/*if (aliases(args) == 0)
	  return (args);*/
	if (search_builtins(args) == 0)
		return (2);
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
		return (2);
	return (0);
}

/**
  * edit_equal_sign - gets rid of chars up until and including the 
  * equal sign in the environment string
  * @s:
  * Return:
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

/**
  *
  *
  *
  */
int search_builtins(char **args)
{
	builtin builtins[] = {
		{"exit", exit_function},
		{"env", print_env},
		{NULL, NULL}
	};

	int x, check;

	check = -1;
	for (x = 0; builtins[x].name != NULL; x++)
	{
		if (_strcmp(builtins[x].name, args[0]) == 0)
			check = builtins[x].func();
	}
	return (check);
}
