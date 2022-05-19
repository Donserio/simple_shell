#include "shell.h"
/**
 * shell_run - does things like run
 * @args: args
 * @line: line
 * Return: 0
 */
void shell_run(char **args, __attribute__((unused))char *line)
{
pid_t pid, pid2;
int status, i;
char parmList[1024] = "/bin/", *newParm, usr[1024] = "/usr";
char *path;
char *usrcmd[19] = {"clear", "touch", "find", "du", "head", "tail", "diff",
		    "wget", "top", "man", "zip", "unzip", "curl", "diff",
		    "free", "groups", "passwd", "env", NULL};

for (i = 0; i < 19; i++)
{
if (args[0][i] == '/' || args[0][i] == '.')
{
	path = *args;
	break;
}
if (_strcmp(args[0], usrcmd[i]) == 0)
{
	newParm = _strcat(usr, parmList), path = _strcat(newParm, args[0]);
	break;
}
else if (i == 18)
{
path = _strcat(parmList, args[0]);
}
}
pid = fork();
if (pid == 0)
{
if (execve(path, args, environ) == -1)
perror("shell");
exit(0);
}
else if (pid < 0)
perror("shell2");
else
{
do {
	pid2 = waitpid(pid, &status, WUNTRACED), kill(pid2, SIGKILL);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}
