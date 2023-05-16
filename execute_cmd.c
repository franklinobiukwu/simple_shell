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
	char *builtin_str[] = {"env"};
	int number_of_builtins, i;

	/*declare array of function pointers*/
	int (*builtin_func[])(char **) = {&_env};

	number_of_builtins = sizeof(builtin_str)/sizeof(char *);
	/*check if builtin*/
	for(i = 0; i < number_of_builtins; i++)
	{
		if ((strcmp(av[0], builtin_str[i]) == 0))
			return ((*builtin_func[i])(av));
	}
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
	int status, flag = 0;
	pid_t pid;
	char *path, *cmd;
	size_t counter;

	/*set path if command is a path*/
	cmd = av[0];
	for (counter = 0; cmd[counter]; counter++)
	{
		if (cmd[counter] == '/')
		{
			flag = 1;
			path = cmd;
			break;
		}
	}
	if (flag != 1)
	{
		/*find executable*/
		path = setpath(av);
	}
	if (path == NULL)
	{
		freeLAP(av, lineptr, path);
		handle_error("command not found", 0);
		return (1);
	}
	/*execute command*/
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, av, NULL) == -1)
		{
			freeLAP(av, lineptr, path);
			handle_error("Execution failed", EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free(lineptr);
	free(av);
	if (flag != 1)
		free(path);

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

/**
 * freeLAP - free buffers linepointer, av, and paths
 *
 * @lineptr: line pointer
 * @av: user input
 * @path: path
 *
 * Return: void
 */

void freeLAP(char **av, char *lineptr, char *path)
{
	free(lineptr);
	free(av);
	free(path);
}
