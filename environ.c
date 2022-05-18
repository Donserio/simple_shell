#include "shell.h"

/**
 * _env - prints the evironment variables
 *
 * @input: input data from getline.
 * @cmd: struct of global variables
 * Return: EXIT_SUCCESS on success.
 */
int _env(char **input)
{
	char **tmp = input;
	tmp = NULL;

	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

char *_getenv(const char *name)
{
	int i, j, start;
	char *envar = NULL;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				start = 0;
				break;
			}
			envar = environ[i];
		}
		if (environ[i][j] == '=')
		{
			start = (j + 1);
			break;
		}
	}
	return (envar + start);
}

char *_which(char *input)
{
	char *path, *cpy_path, *path_toks, *dir;
	int len_dir, len_input, i;
	struct stat st;

	path = _getenv("PATH");

	if (path)
	{
		cpy_path = strdup(path);
		len_input = strlen(input);
		path_toks = strtok(cpy_path, ":");
		i = 0;
		while (path_toks != NULL)
		{
			len_dir = strlen(path_toks);
			dir = malloc(len_dir + len_input + 2);
			strcpy(dir, path_toks);
			strcat(dir, "/");
			strcat(dir, input);
			strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(cpy_path);
				return (dir);
			}
			free(dir);
			path_toks = strtok(NULL, ":");
		}
		free(cpy_path);
		if (stat(input, &st) == 0)
			return (input);
		return (NULL);
	}
	if (input[0] == '/')
		if (stat(input, &st) == 0)
			return (input);
	return (NULL);
}
