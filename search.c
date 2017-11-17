#include "holberton1.h"

/**
  * search - searches directories for the the command
  * @args: contains the commands to search for
  * Return: -1 on failure, 0 on success
  */
int search(char **args)
{
	char **command;
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
		if (chdir(command[x]) == -1)
			perror("chdir failed");
		if (stat(args[0], &sb) != -1)
		{
			args[0] = _strconcat(command[x], args[0]);
			break;
		}
	}
	chdir(cwd);
	/*send command to get freed*/
	if (command[x] == NULL)
		return (-1);
	return (0);
}

/**
  * edit_equal_sign - gets rid of chars up until and including the 
  * equal sign in the environment string
  * @s: the string to modify
  * Return: Nothing, void
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
