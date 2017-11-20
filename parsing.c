#include "holberton1.h"

/**
 * countargs - A function that counts the number of arguments in the string
 * returned by getline.
 *
 * @line: A pointer to a string.
 *
 * Return: An unsigned integer indicating length.
 */
int countargs(char *line)
{
	int i, count, flag, j;
	char *delim = " :";

	flag = i = 0;
	count = 1;
	if (line == NULL)
		return (count);
	while (line[i] != '\0')
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (line[i] == delim[j] && flag == 0)
			{
				count++;
				flag = 1;
				break;
			}
		}
		if (delim[j] == '\0')
			flag = 0;
		i++;
	}
	/*count + 1 because need an extra space to assign NULL*/
	return (count + 1);
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
char **parser(char *line, int size)
{
	char **token_list = malloc(sizeof(char *) * size);
	char *token;
	int i = 0;
	char *delim = " :'\n''\t'";

	if (line == NULL || token_list == NULL)
		return (NULL);
	token = strtok(line, delim);
	while (token != NULL)
	{
		token_list[i] = _strdup(token);
		if (token_list[i] == NULL)
		{
			free_function(2, token_list);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	token_list[i] = token;
	return (token_list);
}


/**
  * edit_equal_sign - gets rid of chars up until and including the
  * equal sign in the environment string
  * @s: the string to modify
  * Return: Nothing, void
  */
void edit_equal_sign(char **s)
{
	int x = 0;

	while (s[0][x] != '=')
	{
		s[0][x] = ':';
		x++;
	}
	s[0][x] = ':';
}
