#include "main.c"

/**
 * _putchar - write character to standard output
 *
 * @c: character to be written to standard output
 *
 * Return: 1 on Success
 * return -1 on error, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - write a string without a trailing new line to standard output
 *
 * @str: string to be written to stdout
 *
 * Return: 0 on success
 */

int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (0);
}
