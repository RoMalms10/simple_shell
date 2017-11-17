#include "holberton1.h"

/**
  * interpreter - interprets args[0] and checks to see which function
  * it should be sent to
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
		{
			/*send args to get freed*/
			return;
		}
		/*will return -1 if failure happened*/
		if (search(args) == -1)
		{
			/*send args to get freed*/
			return;
		}
	}
	execution(args);
}
