#include "holberton1.h"

int main(void)
{
	extern char **environ;
	int x = 0;

	while (environ[x] != NULL)
	{
		printf("%s\n", environ[x]);
		x++;
	}
	return (0);
}
