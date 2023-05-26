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
	int fla, command_count, i, status = 1;

	if (getline(&lineptr, &n, stdin) == -1)/*store user input in lineptr*/
	{
		free(lineptr);
		return (0);
	}
	fla = is_white_space(lineptr);
	if (fla == 1)
	{
		free(lineptr);
		return (1);
	}
	if (lineptr[0] == '\n')
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
		status = exec_builtin(av, lineptr_exec, argv, exec_count,
				commands, lineptr_copy);
	}
	return (status);
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
		freeLAP(NULL, NULL, str, str_dup, NULL);
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

/**
 * is_white_space - checks if a string is white space only
 *
 * @str: string
 *
 * Return: 1 if string is whitespace only
 * 0 if string contains any other characters.
 */

int is_white_space(char *str)
{
	int i, len, flag = 0;

	len = my_strlen(str);

	for (i = 0; i < (len - 1); i++)
	{
		if (str[i] == ' ')
			continue;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return (0);
	return (1);
}
