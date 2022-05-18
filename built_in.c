#include "shell.h"

/**
 * assign_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x';
	char *buffer;
	int r;

	if (input == 0)
	{
		fflush(stream);
	}
	else
	{
		return (-1);
	}

	input = 0;

	//Allocating memory
	buffer = malloc(sizeof(char) * 120);

	// if memory allocation fails
	if (!buffer)
	{
		return (-1);
	}

	//Initialize a loop to read all char if c is not newline
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
		{
			buffer = realloc(buffer, input + 1);
		}

		buffer[input] = c;
		input++;
	}

	//add newline at the end of the buffer
	buffer[input] = '\n';

	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if(r != 0)
	{
		input = 0;
	}
	return (ret);
}
