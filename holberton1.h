#ifndef HOLBERTON_1
#define HOLBERTON_1

#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

typedef struct bin {
	char *name;
	int (*func)(void);
} builtin;

typedef struct ali {
	char *name;
	/*function pointer*/
} alias;

int exit_function(char **args, char *line);
int _atoi(char *s);
int search_dirs(char **command, char **args);
int search_builtins(char **args);
int print_env(void);
int countargs(char *line);
int execution(char **args);
int search(char **args);
int _strcmp(char *s1, char*s2);
int _strlen(char *s);
int interpreter(char **args);
char *find_path(char *name);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *s);
char **parser(char *line, int size);
void edit_equal_sign(char **s);
void free_function(int n, ...);

#endif
