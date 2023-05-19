#include <stddef.h>

/**
 * _strtok - tokenizes a string
 *
 * @str: string to be tokenized
 * @delim: delimiter characters to delimit string by
 *
 * Return: non-empty string
 */
char *_strtok(char *str, const char *delim)
{
    static char *updated_str = NULL;
    char *token;
    int i, j;

    // Return NULL if str is NULL on first call or set str to updated_str on subsequent calls to _strtok
    if (!str && delim)
    {
        if (!updated_str)
            return NULL;
        else
            str = updated_str;
    }

    // Set updated_str to str on first call to _strtok
    if (str && !updated_str)
        updated_str = str;

    // Search for the next delimiter
    for (i = 0; str[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
            {
                token = str;
                str[i] = '\0';
                updated_str = str + i + 1;
                return token;
            }
        }
    }

    if (str[i] == '\0')
    {
        token = str;
        updated_str = NULL;
        return token;
    }

    return NULL;
}

