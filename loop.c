#include "shell.h"

/**
 * loop - run continuous loop
 *
 * Return: 0 on success
 */

int loop(void)
{
	int status = 1;

	environ = make_environ_arr(environ);
	do {
		/*print prompt*/
		if (isatty(0))
			_puts("$ ");
		/*get tokenized user input*/
		status = readline();
		free(environ);
	} while (status);
	return (0);
}
