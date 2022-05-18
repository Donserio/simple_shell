#include "shell.h"

/**
 * _getenv - Gets the environment variable.
 *
 * @name: a character constant for variable name
 *
 * Return: returns environment variable on succss
 * returns zero on fail.
 **/

char *_getenv(char *name)
{
int i;
char **env;

i = _strlen(name);

for (env = environ; *env; env++)
{
	if (strncmp(*env, name, i) == 0)
	{
		return (*env);
	}
}
return (0);
}
