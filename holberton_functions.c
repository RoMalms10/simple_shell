#include "holberton1.h"

/**
  * _strdup - duplicates a string
  * @s: the string to duplicate
  * Return: NULL if malloc fails or if str is NULL, else pointer to new string
  */
char *_strdup(char *s)
{
	char *ptr;
	int i, count;

	count = 0;
	if (s == NULL)
		return (NULL);
	count = _strlen(s);
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

/**
  * _strconcat - concatenate 2 strings in a new string, even when passed NULL
  * used to make the PATH to print out or use commands
  * @s1: the first string
  * @s2: the second string
  * Return: The concatenated string
  */
char *_strconcat(char *s1, char *s2)
{
	char *strcon;
	int i, j, count;

	j = 0;
	count = _strlen(s1) + _strlen(s2) + 2;
	/*+2 to add space for / in between command and path and \0 at the end*/
	strcon = malloc(sizeof(char) * count);
	if (strcon == NULL)
		return (NULL);
	for (i = 0; s1 && s1[i] != '\0'; i++)
	{
		strcon[j] = s1[i];
		j++;
	}
	if (j != 0)
	{
		strcon[j] = '/';
		j++;
	}
	for (i = 0; s2 && s2[i] != '\0'; i++)
	{
		strcon[j] = s2[i];
		j++;
	}
	strcon[j] = '\0';
	/*have to free args[0], since we change what args[0] points to*/
	free_function(1, s2);
	return (strcon);
}

/**
  * _strlen - passed a pointer to an array to count the length
  * @s: the string passed to count
  * Return: x, the value of how long the string is
  */
int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;
	return (count);
}

/**
  * _strcmp - compares the ASCII value of chars in two different strings 1 by 1
  * @s1: the first string to be compared
  * @s2: the second string to be compared
  * Return: The difference between the ASCII value in the strings
  */
int _strcmp(char *s1, char *s2)
{
	int diff, index;

	diff = index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		diff = s1[index] - s2[index];
		if (diff != 0)
			break;
		index++;
	}
	return (diff);
}



/**
  * _atoi - Takes a string and converts the numbers into integers
  * @s: The string to be checked
  * Return: Nothing, void
  */

int _atoi(char *s)
{
	int x;
	unsigned int number = 0;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] > '9' || s[x] < '0')
			return (-1);
	}
	for (x = 0; s[x] != '\0'; x++)
		number = number * 10 + (s[x] - '0');
	return (number);
}
