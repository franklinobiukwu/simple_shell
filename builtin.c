#include "shell.h"

/**
 * _env - prints environmental variables
 *
 * @av: user input comands
 *
 * Return: always 1
 */

int _env(__attribute__((unused))char **av)
{
	size_t i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (1);
}
