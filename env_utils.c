#include "shell.h"

/**
 * make_environ - set environment (linked list style)
 *
 * @str: pointer to environment
 *
 * Return: pointer to list head
 */

env_l *make_environ(char **str)
{
	env_l *head;

	if (!str || !str[0])
		return (NULL);

	/*memory allocation for the head node*/
	head = malloc(sizeof(env_l));
	if (!head)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	head->env_str = strdup(str[0]);
	head->next = make_environ(str + 1);

	return (head);
}

/**
 * _setenv - set new or update environment
 * string (i.e variable and value as string)
 *
 * @name: environment name
 * @value: environment value
 * @overwrite: overwrite environment value if
 * set to nonzero
 *
 * Return: 0 on success, -1 on error
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	env_l *environ_list_ptr;
	char *str;
	int name_len = my_strlen(name);
	int i, count = 0, flag = 0;

	environ_list_ptr = environ_list;

	/*find if env exist*/
	while (environ_list_ptr)
	{
		str = environ_list_ptr->env_str;
		/*check if environment string exist in environ list*/
		for (i = 0; i < name_len; i++)
		{
			/*
			 * flag 1 if first character of environment
			 * string is same as in name
			 */
			if (str[0] == name[0])
				flag = 1;
			if (str[i] == name[i])
			{
				count++;
				continue;
			}
			break;
		}
		if (str[i] == '=' && count == name_len && flag == 1 && overwrite != 0)
		{
			str = set_env_str(name, value);
			return (0);
		}
		else if (str[i] == '=' && flag == 1 && overwrite == 0)
			return (0);

		environ_list_ptr = environ_list_ptr->next;
	}

	return (-1);
}

/**
 * set_env_str - build environment string
 *
 * @name: environment variable
 * @value: environment value
 *
 * Return: environment string
 */

char *set_env_str(const char *name, const char *value)
{
	int name_len, value_len, total_len;
	char *str;

	name_len = my_strlen(name);
	value_len = my_strlen(value);
	total_len = name_len + value_len;
	/*create memory for new string*/
	str = malloc(sizeof(char) * total_len + 1);
	if (str == NULL)
		handle_error("setenv malloc error", EXIT_FAILURE);
	/*initializing memory to enable us concatinate*/
	str[0] = '\0';
	/*concatenate string*/
	my_strcat(str, name);
	my_strcat(str, "=");
	my_strcat(str, value);

	return (str);
}
