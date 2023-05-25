#include "shell.h"


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
	char **env_arr;
	int i, env_pos = 0;
	char *env_str;

	env_arr = malloc(sizeof(char **));
	if (env_arr == NULL)
	{
		perror("setenv failed");
		return (-1);
	}
	/*get position of env variable if exist*/
	env_str = getenvstr(name);
	/*copy environment to new variable*/
	for (i = 0; environ[i]; i++)
	{
		env_arr[i] = my_strdup(environ[i]);
	}
	/*add new environment string if not found in environ*/
	if (env_str == NULL)
	{
		env_arr[i] = set_env_str(name, value);
		env_arr[i + 1] = NULL;
	}
	else if (overwrite != 0)
	{
		env_arr[i] = NULL;
		for (i = 0; environ[i]; i++)
		{
			if (my_strcmp(environ[i], env_str) == 0)
				env_pos = i;
		}
		env_arr[env_pos] = set_env_str(name, value);
	}

	/*point environ to new environ*/
	environ = env_arr;

	return (0);
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
