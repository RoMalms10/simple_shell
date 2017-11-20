#include "holberton1.h"

/**
  * search - searches directories for the the command
  * @args: contains the commands to search for
  * Return: -1 on failure, 0 on success
  */
int search(char **args)
{
	char **command = NULL;
	int count;
	char *hold;

	hold = _strdup(find_path("PATH"));
	if (hold == NULL)
		return (-1);
	count = countargs(hold);
	if (count == -1)
	{
		free_function(1, hold);
		return (-1);
	}
	edit_equal_sign(&hold);
	command = parser(hold, count);
	if (command == NULL)
	{
		free_function(1, hold);
		return (-1);
	}
	if (search_dirs(command, args) == -1)
	{
		free_function(1, hold);
		return (-1);
	}
	free_function(1, hold);
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
		{"env", print_env},
		{NULL, NULL}
	};

	int x, check;

	check = 0;
	for (x = 0; builtins[x].name != NULL; x++)
	{
		if (_strcmp(builtins[x].name, args[0]) == 0 &&
				_strlen(builtins[x].name) == _strlen(args[0]))
			check = builtins[x].func();
	}
	if (builtins[x].name == NULL)
		return (-1);
	return (check);
}

/**
  *
  *
  *
  *
  */
int search_dirs(char **command, char **args)
{
	char *cwd;
	int x;
	struct stat sb;

	cwd = getcwd(NULL, 0);
	for (x = 0; command[x] != NULL; x++)
	{
		chdir(command[x]);
		if (stat(args[0], &sb) != -1)
		{
			args[0] = _strconcat(command[x], args[0]);
			if (args[0] == NULL)
			{
				free_function(1, cwd);
				free_function(2, command);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free_function(1, cwd);
	if (command[x] == NULL)
	{
		free_function(2, command);
		return (-1);
	}
	free_function(2, command);
	return (0);
}
