#include "holberton1.h"

int main(void)
{
	char *line = NULL;
	size_t n = 0;

	printf("$ ");
	getline(&line, &n, stdin);
	printf("%s", line);
	free(line);
	return (0);
}
