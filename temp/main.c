#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_strtok(char *str, char *delim);

int main(void)
{
    char str[] = " : ::-::  ---  : : : : :  ::   :::Obi:is-:a-::boy:::::on\n\n\n::Tiktok\n"; // Create a mutable copy of the string
    char *delim = " : -\n";
    char *token;

    token = _strtok(str, delim);
    while (token)
    {
        printf("%s\n", token);
        token = _strtok(NULL, delim);
    }

    return 0;
}

