#include "shell.h"

/**
 * handle_error - pprinted
 * @exit_code: exit code
 * @msg: error message
 * Return: void
 */

void handle_error(char *msg, int exit_code)
{
	perror(msg);
	if (exit_code == 0)
		return;
	exit(exit_code);
}


/**
 * handle_error_msg - print appropriate error message
 *
 * @argv: program name
 * @count: execution count
 * @cmd: command executed
 * @msg: error message
 *
 * Return: count of character written
 */

int handle_error_msg(char *argv, int count, char *cmd, char *msg)
{
	char *msg_buff;
	char *num_str = _itoa(count);
	int write_count;
	int argv_count = my_strlen(argv);
	int cmd_count = my_strlen(cmd);
	int msg_count = my_strlen(msg);
	int num_count = my_strlen(num_str);
	int total_count = argv_count + cmd_count + msg_count + num_count;

	/*create memory to store message*/
	msg_buff = malloc(sizeof(char *) * total_count + 6);
	if (msg_buff == NULL)
		handle_error("handle error", 0);
	/*copy values to buff*/
	strcat(msg_buff, argv);
	strcat(msg_buff, ":");
	strcat(msg_buff, " ");
	strcat(msg_buff, num_str);
	strcat(msg_buff, ":");
	strcat(msg_buff, " ");
	strcat(msg_buff, cmd);
	strcat(msg_buff, msg);

	write_count = write(STDERR_FILENO, msg_buff, (total_count + 6));

	free(num_str);
	free(msg_buff);
	return (write_count);
}

/**
 * _itoa - convert integer to string
 *
 * @num: number to be converted
 *
 * Return: string
 */

char *_itoa(int num)
{
	int i, mod;
	int temp, count = 0;
	char *character;

	/*count the number of digits*/
	temp = num;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	/*allocate memory to store digits as string*/
	character = malloc(sizeof(char) * (count + 1));
	/*convert each digit to a string*/
	for (i = count - 1; i >= 0; i--)
	{
		mod = num % 10;
		character[i] = mod + '0';
		num /= 10;
	}
	/*terminate the string*/
	character[count] = '\0';

	return (character);
}
