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

/**
 *handle_Commandline_Argu - handle command line arguments
 *@line: input
 *@args: array of pointer to the string
 *@Return: length
 */

int handle_Commandline_Argu(char *line, char **args)
{
	int i = 0;
	char *token, *argu, *cmd;

	argu = line;

	cmd = strtok(line, "\n\t\r ");

	args[i] = cmd;

	while (argu != NULL)
	{
		i++;
		token = strtok(NULL, "\n\t\r");
		argu = token;
		args[i] = token;
	}
	args[i] = NULL;
	return (i);
}
