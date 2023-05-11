#include "main.h"

/**
 * _strlen - determines the length of a string
 *
 * @str: string
 *
 * Return: length of the string
 */

size_t _strlen(const char *str)
{
	size_t count;

	for (count = 0; str[count]; count++)
		;
	return (count);
}

/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: pointer to duplicated string
 */

char *_strdup(const char *str)
{
	size_t len;
	char *buf;
	int i;

	/*return NULL if str is NULL*/
	if(!str)
		return (NULL);
	/*get length of string*/
	len = _strlen(str);
	/*create memory of size len + 1*/
	buf = malloc(sizeof(char *) * (len + 1));
	/*return NULL if malloc fails*/
	if (buff == NULL)
		return (NULL);
	/*copy str to buffer*/
	for (i = 0; str[i]; i++)
		buf[i] = str[i];
	buf[i] = '\0';

	return (buf);
}
