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
	{
		/*if (search_aliases(args) == 0)
			return;*/
		/* will return 0 if the job succeeds, thus don't continue*/
		if (search_builtins(args) == 0)
			return;
		/*will return -1 if failure happened*/
		if (search(args) == -1)
		{
			printf("Args worked\n");
			/*send args to get freed*/
			return;
		}
	}
	execution(args);
}
