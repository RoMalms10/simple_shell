#include "holberton1.h"

/**
 * countargs - A function that counts the number of arguments in the string
 * returned by getline.
 *
 * @line: A pointer to a string.
 *
 * Return: An unsigned integer indicating length.
 */
size_t countargs(char *line)
{
	size_t i, count, flag;

	flag = i = 0;
	count = 1;
	while (line[i] != '\0' && flag == 0)
	{
		if (line[i] == " " && flag == 0)
		{
			count++;
			flag == 1;
		}
		else if (line[i] != " ")
			flag = 0;
		i++;
	}
	return (count);
}

/**
 * parser - A function that parses the arguments passed into token and passes
 * them to a buffer.
 *
 * @line: A pointer to a string entered into the command line.
 * @size: An unsigned integer indicating the number of arguments.
 *
 * Return: A pointer to an array of strings.
 */
char **parser(char *line, size_t size)
{
	char **token_list = malloc(sizeof(char *) * size);
	char *token;
	size_t i = 0;

	if (line == NULL || token_list == NULL)
		exit(EXIT_FAILURE);

	token = strtok(&line, " '\n'", stdin);
	if (token == NULL)
		return (NULL);
	while (i < size)
	{
		token_list[i] = token;
		token = strtok(NULL, " '\n'");
		i++;
	}
	return (token_list);
}
