#include "shell.h"
/**
 * main - main function
 * Return: nothing
 */
int main(void)
{
char *line = NULL;
char **args;
size_t size = 0;
int c;
do {
if (isatty(STDIN_FILENO) == 1)
{
_putchar('$');
_putchar(' ');
}
c = getline(&line, &size, stdin);
if (c == -1)
{
free(line);
exit(0);
}
if (line[0] == '\n')
{
continue;
}
args = tokenizer(line);
if (*args[0] == ' ')
{
free(line);
free(args);
break;
}

shell_builtin(args, line);
free(args);
free(line);
size = 0;
} while (1);
return (0);
}



/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - gkjsgkjw;
 * @dest: kfdjkla
 * @src: fdjkkfjal
 *
 * Return: lkjdalk;f
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int len;

	for (len = 0; dest[len] != 0;)
	{
		len++;
	}

	for (i = 0; src[i] != 0; i++)
		dest[len + i] = src[i];
	return (dest);
}
