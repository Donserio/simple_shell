#include "shell.h"

/**
 * _searchpath - searches the PATH for a command
 * @command: a command like ls, pwd, etc.
 * @fullpath: the found PATH of the command
 * @path: Macro for path
 * Return: returns fullpath
 **/
char *_searchpath(char *command, char *fullpath, char *path)
{
	unsigned int comlen, pathlen, ogplen;
	char *pathcopy, *token;

	comlen = _strlen(command);
	ogplen = _strlen(path);
	pathcopy = malloc(sizeof(char) * ogplen + 1);
	if (!pathcopy)
	{
		return (NULL);
	}
	strcpy(pathcopy, path);
	token = strtok(pathcopy, ":");
	if (!token)
	token = strtok(NULL, ":");
		while (token)
	{
			pathlen = _strlen(token);
			fullpath = malloc(sizeof(char) * (pathlen + comlen) + 2);
		if (!fullpath)
		{
			return (NULL);
		}
		strcpy(fullpath, token);
		fullpath[pathlen] = '/';
		strcpy(fullpath + pathlen + 1, command);
		fullpath[pathlen + comlen + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(pathcopy);
	return (fullpath);
}
