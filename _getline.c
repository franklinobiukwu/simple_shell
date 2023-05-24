#include "shell.h"

void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_linptr(char **linptr, size_t *n, char *buffer, size_t b);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

/**
 * my_realloc - Reallocate memeroy block
 * @ptr: pointer to a memory perviously allocated
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: size in bytes for new memory
 */

void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *ptr_copy, *fill;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}
	ptr_copy = ptr;
	memory = malloc(sizeof(*ptr_copy) * new_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}
	fill = memory;
	for (index = 0; index < old_size && index < new_size; index++)
		fill[index] = *ptr_copy++;
	free(ptr);
	return (memory);
}

/**
 * assign_linptr - reasinged the linpter variables for my_getline
 * @linptr: buffer to store an input
 * @n: size of linptr
 * @buffer: string to asign to linptr
 * @b: size of buffer
 */
void assign_linptr(char **linptr, size_t *n, char *buffer, size_t b)
{
	if (*linptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*linptr = buffer;
	}
	else if (*n < b)
	{
		if (b < 120)
			*n = b;
		else
			*n = 120;
		*linptr = buffer;
	}
	else 
	{
		my_strcpy(*linptr, buffer);
		free(buffer);
	}
}

/**
 * my_getlin - reas input from stream
 * @lineptr: buffer to store input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: number of bytes read
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = my_realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_linptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
