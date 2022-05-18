#include <stdio.h>
#include "shell.h"

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

char **get_toks(char *args, char *delimiter)
{
	int i = 0;
	char *token;
	char **output = malloc(MAXARGS * sizeof(char *));
	if (output == NULL)
		return (NULL);

	token = strtok(args, delimiter);
	while (token != NULL)
	{
		output[i] = token;
		i++;
		if (i > MAXARGS)
			output = realloc(output, (i) * sizeof(char *));
		token = strtok(NULL, delimiter);
	}
	output[i] = NULL;

	return (output);
}

/**
 * str_reverse - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void str_reverse(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
