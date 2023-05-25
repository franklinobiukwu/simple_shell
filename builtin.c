#include "shell.h"

/**
 * _env - prints environmental variables
 *
 * @av: user input comands
 * @lineptr: user input command string
 *
 * Return: always 1
 */

int _env(char **av, char *lineptr)
{
/*	size_t i = 0;*/

	env_l *environ_list_ptr;

	environ_list_ptr = environ_list;

	while (environ_list_ptr)
	{
		_puts(environ_list_ptr->env_str);
		_puts("\n");
		environ_list_ptr = environ_list_ptr->next;
	}

	freeLAP(av, lineptr, NULL);

	return (1);
}

/**
 * exit_shell - exit shell
 *
 * @av: tokenized input command
 * @lineptr: user input command string
 *
 * Return: Always 0
 */

int exit_shell(char **av, char *lineptr)
{
	freeLAP(av, lineptr, NULL);
	exit(0);
}
