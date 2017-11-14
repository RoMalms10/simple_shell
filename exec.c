#include "holberton1.h"

int main(__attribute__((unused))int ac, char **av)
{
	av = av + 1;
	printf("Before execve\n");
	if (execve(av[0], av, NULL) == -1)
	{
		printf("Error\n");
	}
	printf("After execve\n");
	return (0);
}
