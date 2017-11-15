#include "holberton1.h"

int main(void)
{
	size_t n, counter;
	int status;
	char *line, *tokenized;
	char **commands;
	pid_t child_pid;

	n = counter = 0;
	line = tokenized = NULL;
	commands = NULL;
	while (1)
	{
		printf("#cisfun$ ");
		getline(&line, &n, stdin);
		tokenized = strtok(line, " '\n'");
		commands = malloc(sizeof(tokenized));
		if (commands == NULL)
			return (-1);
		while (tokenized != NULL)
		{
			commands[counter] = tokenized;
			tokenized = strtok(NULL, " '\n'");
			counter++;
		}
		commands[counter] = NULL;
		child_pid = fork();
		if (child_pid == 0)
			execve(commands[0], commands, NULL);
		else
			wait(&status);
	}
	free(line);
	free(commands);
	return (0);
}
