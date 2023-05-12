#include <stdio.h>
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

/**
 * strcat - function to concatenate a string
 * @dest: destination
 * @src: source
 * Return: string
 */
char *strcat(char *dest, const char src)
{
	int i, j;
	for (i = 0; dest[i] != '\0'; i++)
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * strdup - function to duplicate a string
 * @str - string
 * Return - new_string
 */
char *strdup(const char* str)
{
	size_t length = strlen(str);
	char *new_str = malloc(length + 1);
	if(*new_str = NULL)
	{
		return (NULL);
	}
	strcpy(new_str, str);
	return (new_str);
}
