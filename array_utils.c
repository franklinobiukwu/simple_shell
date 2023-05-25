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

/**
 * free_arr - free aarray of strings
 *
 * @arr: array of strings
 *
 * Return: void
 */

void free_arr(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
