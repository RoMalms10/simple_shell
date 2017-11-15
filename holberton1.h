#ifndef HOLBERTON_1
#define HOLBERTON_1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct environment {
	char *str;
	char *next;
} stuff;

extern char **environ;

char *_getenv(const char *name);

#endif
