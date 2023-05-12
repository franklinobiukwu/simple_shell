#include "shell.h"

/**
 * readline - read and procees user input for execution
 *
 * Return: pointer to tokemized user input
 */

char **readline(void)
{
	char *lineptr_dup, *lineptr = NULL;
	char  *token, *delim = " \n";
	size_t n = 0;
	int counter = 0;
	char **av;

	/*store user input in lineptr*/
	if (getline(&lineptr, &n, stdin) == -1)
		handle_error("getline error", EXIT_FAILURE);
	/*tokenize user input*/
	/*--duplicate user command--*/
	lineptr_dup = strdup(lineptr);
	/*--count each user input string--*/
	token = strtok(lineptr_dup, delim);
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	/*--create buffer to store tokenized user input string--*/
	av = malloc(sizeof(char *) * (counter + 1));
	if (av == NULL)
	{
		free(lineptr);
		free(lineptr_dup);
		handle_error("malloc error", 0);
	}
	counter = 0;
	/*--tokenize user input--*/
	token = strtok(lineptr, delim);
	while (token)
	{
		av[counter] = token;
		token = strtok(NULL, delim);
		counter++;
	}
	av[counter] = NULL;
	return (av);
}

/**
 * handle_error - print error message and exit process
 *
 * @msg: error message to be printed
 * @code: exit code
 *
 * Return: void
 */

void handle_error(char *msg, int code)
{
	perror(msg);
	if (code == 0)
		return;
	exit(code);
}
