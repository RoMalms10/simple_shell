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

	/* will return 0 if the job succeeds, thus don't continue*/
	if (search_builtins(args) == 0)
		return (0);
	/*will return -1 if failure happened*/
	search(args);
	/*S_ISREG checks to see if args[0] is a file*/
	/*Will return 0 if it's not a file*/
	if (stat(args[0], &sb) == -1) /*if stat doesn't find anything*/
		return (-1);
	/*if stat populates the struct, check if it's a file*/
	if (stat(args[0], &sb) == 0 && S_ISREG(sb.st_mode) == 0)
		return (-1);
	if (execution(args) == -1)
		return (-1);
	return (0);
}

/**
  * free_function - frees malloc'd spaces based on what number is passed
  * @n: signifies whether to free a single pointer or double pointer
  * Return: nothing, void
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

/**
  * err_mess - prints an error message "not found" when something doesn't work
  *
  * @argv: the list of pointers to argument variables
  * Used to print the name of the program
  *
  * @args: the arguments collected by getline
  *
  * @loops: the number of times the infinite loop has been executed
  *
  *Return: nothing, void
  */
void err_mess(char **argv, char **args, int loops)
{
	char *space = ": ";
	char *err1 = "not found";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, space, _strlen(space));
	err_num(loops);
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, err1, _strlen(err1));
	write(STDERR_FILENO, "\n", 1);
}

/**
  * err_num - prints numbers using write
  * @loops: The integer to print
  * Return: nothing, void
  */

void err_num(int loops)
{
	int x;
	unsigned int n;
	char num;

	n = loops;
	x = 1;
	while ((n / x) > 9)
		x *= 10;
	while (x >= 1)
	{
		num = ((n / x) % 10) + '0';
		write(STDERR_FILENO, &num, 1);
		x /= 10;
	}
}
