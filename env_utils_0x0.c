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

	head->env_str = my_strdup(str[0]);
	head->next = make_environ(str + 1);

	return (head);
}


/**
 * make_environ_arr - set environment (string array style)
 *
 * @str: pointer to environment
 *
 * Return: pointer to list head
 */

char **make_environ_arr(char **str)
{
	char **env_arr;
	int i;

	for (i = 0; str[i]; i++)
		;
	/*allocate memory for environment variable*/
	env_arr = malloc(sizeof(char *) * (i + 1));
	for (i = 0; str[i]; i++)
	{
		env_arr[i] = my_strdup(str[i]);
	}
	env_arr[i] = NULL;

	return (env_arr);
}

/**
 * getenvstr - return pointer to environment string
 *
 * @name: environment variable name
 *
 * Return: pointer to environment string
 */

char *getenvstr(const char *name)
{
	char *envstr;
	size_t i, j;
	int flag = 0;

	/*determine length of name*/
	size_t len = my_strlen(name);
	/*
	 * check through each environment string for
	 * desired environment sring with value name
	 */
	for (i = 0; environ[i]; i++)
	{
		envstr = environ[i];
		/*loop through each envronment string*/
		for (j = 0; j < len; j++)
		{
			/*
			 * flag 1 if first charater of environment
			 * is same as in name
			 */
			if (envstr[0] == name[0])
				flag = 1;
			if (envstr[j] == name[j])
				continue;
			break;
		}
		/*flag 2 if next charater after envirnment name is "="*/
		if (envstr[j] == '=' && flag == 1)
			return (envstr);
	}

	return (NULL);
}
