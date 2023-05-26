#include "shell.h"

/**
 * loop - run continuous loop
 *
 * @argv: program name
 *
 * Return: 0 on success
 */

int loop(char *argv)
{
	int status = 1;
	int exec_count = 0;

	do {
		exec_count += 1;
		/*print prompt*/
		if (isatty(0))
			_puts("$ ");
		/*get tokenized user input*/
		status = readline(argv, exec_count);
	} while (status);

	return (0);
}
