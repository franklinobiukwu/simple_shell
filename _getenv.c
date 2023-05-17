#include "shell.h"

/**
 * _getenv - function that returns environment value
 *
 * @variable: environment key/variable
 *
 * Return: environment value
 */

char *_getenv(char *variable)
{
	size_t i, j;
	char *envstr;
	size_t len = my_strlen(variable);

	for (i = 0; environ[i]; i++)
	{
		envstr = environ[i];
		/*compare variable with envstr*/
		for (j = 0; j < len; j++)
		{
			if (envstr[j] == variable[j])
				continue;
			break;
		}
		/*check if character after variable name is "="*/
		if (j == len && envstr[j] == '=')
			return (_strstr(envstr, "="));
	}

	return (NULL);
}
