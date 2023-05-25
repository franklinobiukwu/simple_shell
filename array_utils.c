#include "shell.h"

/**
* count_array_elem - count element of array of strings
*
* @arr: array of strings
*
* Return: number for string elements
*/

int count_array_elem(char **arr)
{
	int i;

	/*return 0 if arr is NULL*/
	if (arr == NULL)
		return (0);
	/*count elements*/
	for (i = 0; arr[i]; i++)
		;
	return (i);
}
