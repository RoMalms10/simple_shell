#include "holberton1.h"

int count_line(char *line);
char **str_tok(char *line, int size);
void execute(char **commands);
char *_strdup(char *str);

int main(void)
{
	char *line = NULL;
	size_t n = 0; 
	int status, malloc_size;
	char **commands = NULL;
	pid_t my_pid;

	while (1)
	{
		printf("$ ");
		getline(&line, &n, stdin);
		my_pid = fork();
		if (my_pid == 0)
		{
			malloc_size = count_line(line);
			commands = str_tok(line, malloc_size);
			execute(commands);
		}
		else if (my_pid == -1)
		{
			/*error*/
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}

int count_line(char *line)
{
	int x, count, flag;
	char delim = ' ';

	x = flag = 0;
	for (count = 1; line[x] != '\0'; x++)
	{
		if (line[x] == delim && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (line[x] != delim)
			flag = 0;
	}
	return (count);
}

char **str_tok(char *line, int size)
{
	char **commands = NULL;
	unsigned int x = 0;
	char *tokenized = NULL;

	commands = malloc(sizeof(char *) * size);
	tokenized = strtok(line, " '\n'");
	while (tokenized != NULL)
	{
		commands[x] = _strdup(tokenized);
		tokenized = strtok(NULL, " '\n'");
		x++;
	}
	return (commands);
}

/**
  * _strdup - duplicates a string
  * @str: the string to duplicate
  * Return: NULL if malloc fails or if str is NULL, else pointer to new string
  */
char *_strdup(char *str)
{
	char *ptr;
	int i, count;

	count = 0;
	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		count++;
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
		return (ptr);
}

void execute(char **commands)
{
	pid_t the_pid;
	int status;

	the_pid = fork();
	if (the_pid == 0)
	{
		execve(commands[0], commands, NULL);
	}
	else if (the_pid == -1)
	{
		/*error*/
	}
	else
	{
		wait(&status);
	}
}
