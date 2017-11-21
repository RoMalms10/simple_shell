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

/**
  * struct bin - contains variables that hold builtin information
  * @name: the name of the builtin
  * @func: the function pointer to the builtin
  */
typedef struct bin
{
	char *name;
	int (*func)(void);
} builtin;

extern char **environ;

int exit_function(char **args, char *line);
int _atoi(char *s);
int search_dirs(char **command, char **args);
int search_builtins(char **args);
int print_env(void);
int countargs(char *line);
int execution(char **args);
int search(char **args);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int interpreter(char **args);
char *find_path(char *name);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *s);
char **parser(char *line, int size);
void edit_equal_sign(char **s);
void free_function(int n, ...);
void err_mess(char **argv, char **args, int loops);
void err_num(int loops);
void _sigign(int sig);

#endif
