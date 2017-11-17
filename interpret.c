#include "holberton1.h"

/**
  * interpreter - interprets args[0] and checks to see which function
  * it should be sent to
  * @args: arguments to pass to execution
  * Return: nothing, void
  */
int interpreter(char **args)
{
	struct stat sb;

	if (stat(args[0], &sb) == -1)
	{
		/*if (search_aliases(args) == 0)
			return;*/
		/* will return 0 if the job succeeds, thus don't continue*/
		if (search_builtins(args) == 0)
			return (0);
		/*will return -1 if failure happened*/
		if (search(args) == -1)
			return (-1);
	}
	if (execution(args) == -1)
		return (-1);
	return (0);
}

/**
  *
  *
  *
  */
void free_function(int n, ...)
{
	char **dblptr;
	char *sglptr;
	va_list valist;
	int idx;

	va_start(valist, n);
	if (n == 1)
	{
		sglptr = va_arg(valist, char *);
		if (sglptr == NULL)
			return;
		free(sglptr);
	}
	if (n == 2)
	{
		dblptr = va_arg(valist, char **);
		if (dblptr == NULL)
			return;
		for (idx = 0; dblptr[idx] != NULL; idx++)
			free(dblptr[idx]);
		free(dblptr);
	}
	va_end(valist);
}
