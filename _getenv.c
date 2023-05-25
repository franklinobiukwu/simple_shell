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
	size_t i;
	char *envstr;
	size_t len = my_strlen(variable);
	env_l *environ_list_ptr;

	environ_list_ptr = environ_list;

	while (environ_list_ptr)
	{
		envstr = environ_list_ptr->env_str;
		/*compare variable with envstr*/
		for (i = 0; i < len; i++)
		{
			if (envstr[i] == variable[i])
				continue;
			break;
		}
		/*chaeck if character after variable name is "="*/
		if (i == len && envstr[i] == '=')
			return (_strstr(envstr, "="));
		environ_list_ptr = environ_list_ptr->next;
	}
	/*old code*/
/*	for (i = 0; environ[i]; i++)*/
/*	{*/
/*		envstr = environ[i];*/
		/*compare variable with envstr*/
/*		for (j = 0; j < len; j++)*/
/*		{*/
/*			if (envstr[j] == variable[j])*/
/*				continue;*/
/*			break;*/
/*		}*/
		/*check if character after variable name is "="*/
/*		if (j == len && envstr[j] == '=')*/
/*			return (_strstr(envstr, "="));*/
/*	}*/

	return (NULL);
}
