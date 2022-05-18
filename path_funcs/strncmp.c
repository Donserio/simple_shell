#include "shell.h"

/**
 * _strncmp - compares items in strings until n
 * @s1: string 1
 * @s2: string 2
 * @n: the limit number you use to compare strings
 * Return: returns 1 if the strings are null, returns 0 if succeeds.
 */

int _strncmp(char *s1, char *s2, int n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
		else
	{
		return (*(char *)s1 - *(char *)s2);
	}
}
