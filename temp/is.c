#include <stdio.h>
#include <unistd.h>

/**
 * main - test isatty function
 *
 *
 * Return: 0 on success
 */

int main(void)
{
	if (isatty(0))
		printf("This is from the terminal");
	else
		printf("This is a user");

	return (0);
}
