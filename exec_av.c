#include "holberton1.h"

int main(int ac, char **av)
{
	char **arguments;
	size_t n, counter;

	arguments = malloc(sizeof(char *) * (ac + 1));
	if (arguments == NULL)
		return (1);
	counter = 1;
	n = 0;
	while (av[counter] != NULL)
	{
		arguments[n] = av[counter];
		counter++;
		n++;
	}
	arguments[counter] = NULL;
	printf("Before execve\n");
	if (execve(arguments[0], arguments, NULL) == -1)
	{
		printf("Error\n");
	}
	printf("After execve\n");
	free(arguments);
	return (0);
}
