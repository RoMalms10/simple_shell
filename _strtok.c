#include "holberton1.h"

int main(void)
{
	char *line = NULL;
	char *tokenized;
	size_t n = 0;
	
	printf("$ ");
	getline(&line, &n, stdin);
	printf("%s", line);
	tokenized = strtok(line, " '\n'");
	while (tokenized != NULL)
	{
		printf("printing: %s\n", tokenized);
		tokenized = strtok(NULL, " '\n'");
	}
        free(line);
        return (0);
}
