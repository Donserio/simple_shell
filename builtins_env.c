#include "shell.h"
/**
 * _strlen - determine the length of a string
 * @s: pointer to the string to check
 * Return: length of the string check
*/


int _strlen(char *s)
{
int i = 0;
while (s[i])
	i++;

return (i);
}
