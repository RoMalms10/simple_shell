#ifndef HOLBERTON_1
#define HOLBERTON_1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct bin {
	char *name;
	/*function pointer*/
} built-in;

typedef struct ali {
	char *name;
	/*function pointer*/
} alias;

int _strcmp(char *s1, char*s2);
int _strlen(char *s);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *s);

#endif
