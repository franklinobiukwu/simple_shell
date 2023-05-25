#include "shell.h"

/**
 * print_arr - print array elements
 *
 * @arr: array
 *
 * Return: void
 */

void print_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
	{
		printf("%s\n", arr[i]);
	}
}
