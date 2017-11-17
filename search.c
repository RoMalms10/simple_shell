#include "holberton1.h"

/**
  * search - searches directories for the the command
  * @args: contains the commands to search for
  * Return: -1 on failure, 0 on success
  */
int search(char **args)
{
	char **command = NULL;
	char *name = "PATH";
	int x, count;
	char *hold, *cwd;
	struct stat sb;

	cwd = getcwd(NULL, 0);
	hold = _strdup(find_path(name));
	if (hold == NULL)
		return (-1);
	count = countargs(hold);
	edit_equal_sign(&hold);
	command = parser(hold, count);
	for (x = 0; command[x] != NULL; x++)
	{
		if (stat(args[0], &sb) != -1)
		{
			args[0] = _strconcat(command[x], args[0]);
			break;
		}
	}
	chdir(cwd);
	free_function(1, cwd);
	free_function(1, hold);
	if (command[x] == NULL)
	{
//		free_function(2, command);
		return (-1);
	}
//	free_function(2, command);
	return (0);
}

/**
  * search_builtins - searches the builtins for their functions
  * @args: contains the command to search for
  * Return: 0 on success
  */
int search_builtins(char **args)
{
	builtin builtins[] = {
		{"exit", exit_function},
		{"env", print_env},
		{NULL, NULL}
	};

	int x, check;

	check = 0;
	for (x = 0; builtins[x].name != NULL; x++)
	{
		if (_strcmp(builtins[x].name, args[0]) == 0)
			check = builtins[x].func();
	}
	if (builtins[x].name == NULL)
		return (-1);
	return (check);
}
