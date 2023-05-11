#include "main.h"

/**
 * main - a simple shell program
 *
 * @ac: argument count passed from terminal
 * @av: argument vector from terminal
 *
 * Return: 0 on failure
 */

int main(int ac, char **av)
{
	if (isatty(0))
	{
		/*non-interractive mode*/
	}
	else
	{
		/*interactive mode*/
	}
}
