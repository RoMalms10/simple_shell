#include "holberton1.h"

int main(void)
{
	char **arguments;
	char *line, *tokenized;
	size_t n, counter;
	int status;
	pid_t child_pid;

	n = 0;
	printf("$ ");
	line = NULL;
	getline(&line, &n, stdin);
	printf("%lu\n", n);
	arguments = malloc(sizeof(char *) * 3);
	if (arguments == NULL)
		return (-1);
	tokenized = strtok(line, " '\n'");
	counter = 0;
	while (tokenized != NULL)
	{
		arguments[counter] = tokenized;
		tokenized = strtok(NULL, " '\n'");
		counter++;
	}
	arguments[counter] = NULL;
	counter = 0;
	while (counter < 5)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
				printf("Error\n");
			return (0);
		}
		else
		{
			wait(&status);
		}
		counter++;
	}
	free(line);
	free(arguments);
	return (0);
}
