#include "shell.h"

/**
 * exec_builtin - execute built in commands
 *
 * @av: tokonized user commands
 * @lineptr: untokenized user command
 * @argv: program name
 * @exec_count: execution count
 * @commands: array of user commands
 * @lineptr_copy: element of commands array
 *
 * Return: 1 on success
 */

int exec_builtin(char **av, char *lineptr, char *argv, int exec_count,
		char **commands, char *lineptr_copy)
{
	char *builtin_str[] = {"env", "exit", "cd"};
	int number_of_builtins, i;

	/*declare array of function pointers*/
	int (*builtin_func[])(char **, char *, char **, char *) = {
		&_env, &exit_shell, &_cd};

	number_of_builtins = sizeof(builtin_str) / sizeof(char *);
	/*check if builtin*/
	for (i = 0; i < number_of_builtins; i++)
	{
		if ((my_strcmp(av[0], builtin_str[i]) == 0))
			return ((*builtin_func[i])(av, lineptr,
						commands, lineptr_copy));
	}
	/*builtin exec*/
	/*return */
	return (exec_exec(av, lineptr, argv, exec_count,
				commands, lineptr_copy));
}

/**
 * exec_exec - execute other commands
 *
 * @av: tokenzed user commands
 * @lineptr: untokenized user command
 * @argv: program name
 * @exec_count: execution count
 * @commands: array of user commands
 * @lineptr_copy: element of commands array
 *
 * Return: 1 on success
 */

int exec_exec(char **av, char *lineptr, char *argv, int exec_count,
		char **commands, char *lineptr_copy)
{
	int status, flag = 0;
	pid_t pid;
	char *path, *cmd;
	size_t counter;

	cmd = av[0];/*set path if command is a path*/
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
		path = setpath(av);/*find executable*/
	if (path == NULL)
	{
		handle_error_msg(argv, exec_count, av[0], " not found\n");
		freeLAP(av, commands, lineptr, path, lineptr_copy);
		return (1);
	}
	/*execute command*/
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, av, NULL) == -1)
		{
			freeLAP(av, commands, lineptr, path, lineptr_copy);
			handle_error("Execution failed", EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	freeLAP(av, commands, lineptr, lineptr_copy, NULL);
	if (flag != 1)
		free(path);
	return (1);
}

/**
 * handle_Commandline_Argu - handle command line arguments
 * @line: input
 * @args: array of pointer to the string
 * Return: length
 */

int handle_Commandline_Argu(char *line, char **args)
{
	int i = 0;
	char *token, *argu, *cmd;

	argu = line;

	cmd = _strtok(line, "\n\t\r ");

	args[i] = cmd;

	while (argu != NULL)
	{
		i++;
		token = _strtok(NULL, "\n\t\r");
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
 * @commands: array of user commands
 * @lineptr_copy: element of commands array
 *
 * Return: void
 */

void freeLAP(char **av, char **commands, char *lineptr,
		char *path, char *lineptr_copy)
{
	if (av != NULL)
		free(av);
	if (commands != NULL)
		free(commands);
	if (lineptr != NULL)
		free(lineptr);
	if (path != NULL)
		free(path);
	if (lineptr_copy != NULL)
		free(lineptr_copy);
}
