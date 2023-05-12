#include "shell.h"

/**
 * _strlen - determines the length of a string
 *
 * @str: string
 *
 * Return: length of the string
 */

size_t _strlen(char *str)
{

	size_t count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * strcpy - function to copy string
 * @dest: destination
 * @str: source
 * Return: string
 */

char *strcpy(char *dest, const char *str)
{
	char *p = dest;

	while (*str != '\0')
	{
		*p++ = *str++;
	}
	*p = '\0';
	return (dest);
}
