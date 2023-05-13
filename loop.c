#include "shell.h"

/**
 * loop - run continuous loop
 *
 * Return: 0 on success
 */

int loop(void)
{
	int status = 1;

	do {
		/*print prompt*/
		_puts("fsh$ ");
		/*get tokenized user input*/
		status = readline();
	} while (status);
	return (0);
}
