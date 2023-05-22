#ifndef SHELL_H
#define SHELL_H

/*HEADER FILES*/
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>

extern char **environ;

/*PROTOTYPES*/
char *_getenv(char *variable);
char *_strstr(char *haystack, const char *needle);

/*str_utils*/
size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
/*io_utils*/
int _putchar(char c);
int _puts(char *str);
int my_strcmp(const char *str1, const char *str2);
/*readline*/
int readline(void);
char **tokenize(char *str, char *delim);
void handle_error(char *msg, int exit_code);
/*exec_cmd*/
int exec_builtin(char **av, char *lineptr);
int exec_exec(char **av, char *lineptr);
int handle_Commandline_Argu(char *line, char **args);
void freeLAP(char **av, char *lineptr, char *path);
/*builtin*/
int _env(char **av, char *lineptr);
int exit_shell(char **av, char *lineptr);

/*loop*/
int loop(void);
/*path*/
char *setpath(char **av);
char *check_exec(char **path_arr, char *cmd, char *paths);
/*_strtok*/
char *_strtok(char *str, const char *delim);
char *skip_preceeding_delim(char *str, const char *delim);
/* _getline */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
int my_fgetc(FILE *stream);
int my_fileno(FILE *stream);
#endif
