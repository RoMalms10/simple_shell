## Simple Shell
### Synopsis
The simple shell project is a collaborative project to explore and understand the functionality and implementation of the shell command language.

### Environment
Our shell was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox.

### Repository Contents
Our shell includes the following files:

|  **File**  |   **Description**   |
| ------------ | --------------------- |
| builtins.c | Contains the exit, printenv, and _sigign functions |
| env_func.c | Contains the find_path function |
| execution.c | Contains the execution function |
| holberton1.h | Contains C standard library header files, and struct and function declarations |
| holberton_functions.c | Contains the _stdup, _strconcat, _strlen, _strcmp, and _atoi functions |
| interpret.c | Contains the interpreter, free_function, err_mess, and err_num functions |
| parsing.c | Contains the countargs, parser, and edit_equal_sign functions |
| search.c | Contauns the search, search_builtins, and search_dirs functions |
| shell.c | Contains the main function |

### Description of Functions

| **Function** | **Description** |
| -------------- | ---------------- |
| int exit_function(char **args, char *line) | Frees the memory allocated to the 'args' string array and 'line' string before exiting the shell. |
| int print_env(void) | Prints a list of the current users environment variables. |
| void _sigign(int sig) | Checks if the end of transmission (ctrl + c) signal was entered and ignores it |
| char *find_path(char *name) | Locates the PATH variable in the environment. Returns a string containing the PATH. |
| int execution(char **args) | Creates a child process and executes a new program within it. Returns an integer value indicating success or failure. |
| char *_strdup(char *s) | Duplicates a string and returns a pointer to the newly allocated space in memory |
| char *_strconcat | Concatenates 2 strings in a new string, even when passed NULL. This is used to make the PATH print out commands. Returns a pointer to the new string. |
| int _strlen(char *s) | Returns the length of a string. |
| int _strcmp(char *s1, char *s2 | Compares the ASCII value of chars in two different string char by char. Returns the difference between the ASCII values. |
| int _atoi(char *s) | Converts a string of ASCII integer chars and converts them to integer values. The return value is unused. |
| int interpreter(char**args) | Interprets the args[0] value's type, and passes the string of arguments to the search_builtins, search, or execution functions, depending on whether args[0] is a command, builtin, or file. |
| void free_function(int n, ...) | A variadic function which frees malloc'd spaces based on which number is passed. Void return. |
| void err_mess(char **argv, char **args, int loops) | A function which prints the error message 'not found' when something does not work. |
| void err_num(int loops) | Prints numbers indicating an error using the write system call. |
| int countargs(char *line) | Counts the number of arguments in the string returned by getline. |
| char **parser(char *line, int size) | Parses the arguments passed into token and passes them to a buffer. |
| void edit_equal_sign(char **s) | Removes all chars up to and including the equal sign in the environment string. |
| int search(char**args) | A function which passes the command line arguments to the countargs, free_function, edit_equal_sign, parser, and/or search_dirs functions depending on its contents. |
| int search_builtins(char **args) | A function which searches for builtin functions. Returns a 0 on success. |
| int search_dirs(char **command, char **args) | Searches the local directories until a correct command is found. Returns 0 on successfully finding command and -1 if it is not found. |
| int main(__attribute__ ((unused)) int argc, char **argv) | Creates a loop within which the user is prompted to enter a command. Once entered, the shell parses and stores the entered text, and attempts to find the correct command. Upon successfully finding the command, the shell executes and then proceeds to free allocated memory. |

### How to Install
Clone the below repository and compile the files into an executable using the GCC compiler.
```
https://github.com/RoMalms10/simple_shell
```

### Compilation

This code was compiled with the following flags:
     (hbtn) $ gcc -Wall -Werror -pedantic *.c -o hsh

### Example Code

```
(hbtn)$ ./hsh
$ ls -l
total 76
-rw-rw-r-- 1 vagrant vagrant  2410 Nov 20 21:04 #holberton_functions.c#
-rw-rw-r-- 1 vagrant vagrant     8 Nov 10 01:06 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  4356 Nov 20 21:34 README.md
-rw-rw-r-- 1 vagrant vagrant   772 Nov 20 20:19 builtins.c
-rw-rw-r-- 1 vagrant vagrant   406 Nov 20 20:19 env_func.c
-rw-rw-r-- 1 vagrant vagrant   482 Nov 20 20:19 execution.c
-rw-rw-r-- 1 vagrant vagrant  1100 Nov 20 20:19 holberton1.h
-rw-rw-r-- 1 vagrant vagrant  2410 Nov 20 20:19 holberton_functions.c
-rwxrwxr-x 1 vagrant vagrant 18583 Nov 20 21:36 hsh
-rw-rw-r-- 1 vagrant vagrant  2445 Nov 20 20:19 interpret.c
-rw-rw-r-- 1 vagrant vagrant   584 Nov 17 01:20 man_one_simple_shell
-rw-rw-r-- 1 vagrant vagrant  1701 Nov 20 20:19 parsing.c
-rw-rw-r-- 1 vagrant vagrant  2023 Nov 20 20:19 search.c
-rw-rw-r-- 1 vagrant vagrant  1078 Nov 20 20:19 shell.c
```

### Notes
Other shell programs are currently in development.

### To do List
Expand the functionality of the shell to account for special characters, add the ability to change environment variables, and add more commands such as cd and history.

### Authors

* [**Robert Malmstein**](https://github.com/RoMalms10)
* [**Jesse Hedden**](https://github.com/jagrvargen)
