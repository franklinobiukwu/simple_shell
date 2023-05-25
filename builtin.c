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
	size_t i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
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
	free_arr(environ);
	exit(0);
}


/**
 * _cd - change directory of simple shell
 *
 * @av: argument from user command input
 * @lineptr: user input command string
 *
 * Return: 1 on success
 */

int _cd(char **av, char *lineptr)
{
	if (av[1] == NULL)
	{
		perror("cd $HOME yet to be implemented");
	}
	else
	{
		if (chdir(av[1]) != 0)
			perror("Change directory error");
	}
	freeLAP(av, lineptr, NULL);

	return (1);
}
