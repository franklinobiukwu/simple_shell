#include "shell.h"

/**
 * readline - read and procees user input for execution
 *
 * Return: 1 on success
 */

int readline(void)
{
	char *lineptr_dup, *lineptr = NULL;
	char  *token, *delim = " \n";
	size_t n = 0;
	int counter = 0;
	char **av;

	if (getline(&lineptr, &n, stdin) == -1)/*store user input in lineptr*/
		handle_error("getline error", EXIT_FAILURE);
	/*tokenize user input*/
	lineptr_dup = strdup(lineptr);/*--duplicate user command--*/
	if (lineptr_dup == NULL)
	{
		free(lineptr);
		handle_error("strdup error", EXIT_FAILURE);
	}
	token = strtok(lineptr_dup, delim);/*--count each user input string--*/
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
		handle_error("malloc error", EXIT_FAILURE);
	}
	counter = 0;
	token = strtok(lineptr, delim);/*--tokenize user input--*/
	while (token)
	{
		av[counter] = token;
		token = strtok(NULL, delim);
		counter++;
	}
	av[counter] = NULL;
	free(lineptr_dup);/*free(lineptr);*/
	return (exec_builtin(av, lineptr));/*execute user command*/
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
