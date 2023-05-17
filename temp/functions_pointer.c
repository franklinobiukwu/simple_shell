#include <stdint.h>
#include <stdio.h>

int64_t add(int64_t, int64_t);
int64_t sub(int64_t, int64_t);

int main()
{
	const char *str = "static";
	printf("str: %p\n", str);
	printf("main: %p\n", main);
}

int64_t add(int64_t a, int64_t b)
{
	return (a + b);
}

int64_t sub(int64_t a, int64_t b)
{
	return (a - b);
}
