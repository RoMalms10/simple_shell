#include "holberton1.h"

int main(int ac, char **av)
{
	int counter;

	counter = 0;
	while (av[counter] != NULL)
	{
		printf("%s ", av[counter]);
		counter++;
	}
	printf("\n");
	return (0);
}
