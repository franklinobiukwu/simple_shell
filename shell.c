#include "shell.h"

/**
 * main - a simple shell program
 *
 * @ac: argument count passed from terminal
 * @av: argument vector from terminal
 *
 * Return: 0 on failure
 */

int main(__attribute__((unused))int ac, char **av)
{

	loop(av[0]);
	return (0);
}
