#include "shell.h"

/**
 * my_exit - built-in function to exit the shell
 *
 */
void  my_exit(void)
{
	char *command = "exit";

	while (1)
	{
		if (strcmp(command, "exit") == 0)
		{
			exit_shell();
		}
	}

}

/**
 * exit_shell - exit function
 */

void exit_shell(void)
{
	exit(0);
}
