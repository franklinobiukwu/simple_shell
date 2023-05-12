#include "shell.h"

/**
 * loop - run continuous loop
 *
 * Return: dky
 */

int loop(void)
{
/*	int i = 0;*/
	char **av;
	int status = 1;

	do {
		/*print prompt*/
		_puts("fsh$ ");
		/*get tokenized user input*/
		av = readline();
		/*execute user command*/
		exec_builtin(av);
	} while (status);
	return (0);
}
