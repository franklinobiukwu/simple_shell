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

/*PROTOTYPES*/

/*shell*/
void handle_error(char *msg, int code);
/*str_utils*/
size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *str);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
/*io_utils*/
int _putchar(char c);
int _puts(char *str);
/*readline*/
int readline(void);
/*exec_cmd*/
int exec_builtin(char **av, char *lineptr);
int exec_exec(char **av, char *lineptr);
int handle_Commandline_Argu(char *line, char **args);

/*loop*/
int loop(void);

#endif
