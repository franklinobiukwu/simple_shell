#include "shell.h"

/**
 * exec_builtin - execute built in commands
 *
 * @av: tokonized user commands
 * @lineptr: untokenized user command
 *
 * Return: 1 on success
 */

int exec_builtin(char **av, char *lineptr)
{
	/*check if builtin*/
	/*builtin exec*/
	/*return */
	return (exec_exec(av, lineptr));
}

/**
 * exec_exec - execute other commands
 *
 * @av: tokenzed user commands
 * @lineptr: untokenized user command
 *
 * Return: 1 on success
 */

int exec_exec(char **av, char *lineptr)
{
	int status;
	pid_t pid;
	/*find executable*/
	/*--check environmental path--*/
	/*execute command*/
	pid = fork();
	if (pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		{
			free(lineptr);
			free(av);
			handle_error("Execution failed", EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(lineptr);
	free(av);

	return (1);
}
