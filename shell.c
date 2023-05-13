#include "shell.h"

/**
 * main - a simple shell program
 *
 * @ac: argument count passed from terminal
 * @av: argument vector from terminal
 *
 * Return: 0 on failure
 */

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	if (!isatty(0))
	{
		/*non-interractive mode*/

		/*get and execute user command*/
		readline();
	}
	else
	{
		/*interactive mode*/
		loop();
	}
	return (0);
}
