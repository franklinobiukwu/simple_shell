#include <stdio.h>

void main(void)
{
	char *str = "Alibaba";

	str += 2;
	printf("%s\n", str);
	printf("%c\n", str[0]);
}
