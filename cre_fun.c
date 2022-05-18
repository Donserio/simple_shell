#include "shell.h"

/**
 * _wordCount - counts using an unsgn int on how many words there are to parse
 * @str: string to count words in
 * Return: returns unsigned int of number of words
 */
unsigned int _wordCount(char *str)
{
	char *delim = "\n \t :";
	unsigned int wrdCnt, index, flag;

	index = 0;
	flag = 0;
	wrdCnt = 1;

	for (; str[index]; index++)
	{
		if (flag == 0 &&
		    (str[index] == delim[0]
		     || str[index] == delim[1]
		     || str[index] == delim[2]
		     || str[index] == delim[3]
		     || str[index] == delim[4])
		    && str[index + 1] != delim[0]
		    && str[index + 1] != delim[1]
		    && str[index + 1] != delim[2]
		    && str[index + 1] != delim[3]
		    && str[index + 1] != delim[4])
		{
			flag = 1;
			wrdCnt++;
		}
		else
		{
			flag = 0;
		}
	}
	return (wrdCnt);
}
/**
 * _strcmp - compares items in strings and returns a value if they are the same
 * @s1: string 1
 * @s2: string 2
 * Return: returns 1 if the strings are null, returns 0 if succeeds.
 */
int _strcmp(char *s1, char *s2)
{
/* s1 == comp, s2 == to match to */
	int index = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s2[index] && (s1[index] == s2[index]))
		index++;

	if (s1[index] == '\0')
		return (0);
	return (1);
}

/**
 * _strlen - get length of string
 * @str: string to check
 *
 * Return: length of string, -1 on fail
 */
int _strlen(char *str)
{
	int count = 0;

	if (str == NULL)
		return (-1);
	for (; str[count]; count++)
		;
	return (count);
}
/**
 * _astrlen - returns length of every string in array of pointers to strings
 * @str: array of pointers to strings to get length of
 *
 * Return: an array of lengths of strings, arr[0] = len of new array;
 */
int *_astrlen(char **str)
{
	static int arr[1024];
	int i, j, x;

	if (str == NULL || *str == NULL)
		return (NULL);
	/* how many pointers in array */
	for (x = 0; str[x]; x++)
		;
	arr[0] = x;
	for (i = 0; str[i]; i++)
	{
		for (j = 0; str[i][j]; j++)
			;
		arr[i + 1] = j;
	}

	return (arr);
}

/**
 * _strdup - copy a string from source to location
 * @source: string to copy
 * @extra: how many extra bytes to include after end of string
 *
 * Return: pointer to begining of null-term string.
 */
char *_strdup(char *source, unsigned int extra)
{
	char *copy;
	unsigned int i;

	if (source == NULL)
		return (NULL);
	for (i = 0; source[i]; i++)
		;
	copy = malloc(sizeof(char) * i + extra + 1);
	if (copy == NULL)
		return (NULL);
	for (i = 0; source[i]; i++)
		copy[i] = source[i];
	copy[i] = '\0';
	if (extra > 0)
	{
		i++;
		for (extra += i; i < extra; i++)
			copy[i] = '\0';
	}
free(copy);
	return (copy);
}
