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
			printf("Error\n");
	}
	printf("%s\n", environ[x]);
	hold = _strdup(environ[x]);
	printf("%s\n", hold);
	edit_equal_sign(&hold);
	printf("%s\n", hold);
	command = parser(hold, countargs(hold));
	for (x = 0; command[x] != NULL; x++)
	{
		write(STDOUT_FILENO, command[x], 20);
		if (chdir(command[x]) == -1)
			perror("Error\n");
		if (stat(args[0], &sb) != -1)
		{
			args[0] = _strconcat(command[x], args[0]);
			printf("%s\n", args[0]);
			break;
		}
	}
	chdir(cwd);
	if (command[x] == NULL)
		printf("Error\n");
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
