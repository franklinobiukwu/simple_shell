#include "shell.h"

/**
 * exec_builtin - execute built in commands
 *
 * @av: tokonized user commands
 *
 * Return: 1 on success
 */

int exec_builtin(char **av)
{
	/*check if builtin*/
	/*builtin exec*/
	/*return */
	return (exec_exec(av));
}

int exec_exec(char **av)
{
	int status;
	pid_t pid;
	/*find executable*/
	/*--check environmental path--*/
	/*execute command*/
	pid = fork();
	if (pid == 0)
	{
		execve(av[0], av, NULL);
	}
	else
		wait(&status);
	return (1);
}
