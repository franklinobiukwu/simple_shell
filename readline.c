#include "shell.h"

/**
 * readline - read and procees user input for execution
 *
 * @argv: program name
 * @exec_count: execution count
 *
 * Return: 1 on success
 */

int readline(char *argv, int exec_count)
{
	char *lineptr_exec, *lineptr_copy, *lineptr = NULL;
	char *delim = " \n";
	size_t n = 0;
	char **commands, **av;
	int command_count, i, status = 1;

	if (getline(&lineptr, &n, stdin) == -1)/*store user input in lineptr*/
	{
		free(lineptr);
		return (0);
	}
	if (lineptr[0] == '\n' || *lineptr == ' ')
	{
		free(lineptr);
		return (1);
	}
	lineptr_copy = my_strdup(lineptr);
	/*tokenize separated commands*/
	commands = tokenize(lineptr_copy, "&;\n");
	/*count commands array element*/
	command_count = count_array_elem(commands);
	/*loop through each command and execute*/
	free(lineptr);
	for (i = 0; i < command_count; i++)
	{
		/*set lineptr to command*/
		lineptr_exec = my_strdup(commands[i]);
		/*tokenize user input*/
		av = tokenize(lineptr_exec, delim);
		/*execute user command*/
		status = exec_builtin(av, lineptr_exec, argv, exec_count);
	}
	free(lineptr_copy);
	free(commands);
	if (status == 0)
		return (0);
	return (1);
}

/**
 * tokenize - tokenizes a string
 *
 * @str: string to be tokenized
 * @delim: delimeter
 *
 * Return: pointer to tokenized strings
 */

char **tokenize(char *str, char *delim)
{
	char *str_dup, *token;
	char **av;
	int counter = 0;

	/*duplicate str*/
	str_dup = my_strdup(str);
	if (str_dup == NULL)
	{
		free(str);
		handle_error("strdup error", EXIT_FAILURE);
	}
	token = strtok(str_dup, delim);/*--count each user input string--*/
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	/*--create buffer to store tokenized user input string--*/
	av = malloc(sizeof(char *) * (counter + 1));
	if (av == NULL)
	{
		freeLAP(NULL, str, str_dup);
		handle_error("malloc error", EXIT_FAILURE);
	}
	counter = 0;
	token = strtok(str, delim);/*--tokenize user input--*/
	while (token)
	{
		av[counter] = token;
		token = strtok(NULL, delim);
		counter++;
	}
	av[counter] = NULL;
	free(str_dup);/*free(lineptr);*/

	return (av);
}
