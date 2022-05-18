#include "shell.h"

/**
 * shell_builtin - builtin used depends on where it's pointing
 * @args: sjsldks
 * @line: jsdjkfj
 * Return: 0
 **/
int shell_builtin(char **args, char *line)
{
int i = 0, switchOwnArg = 0;
char *builtin[6];
builtin[0] = "";
builtin[1] = "exit";
builtin[2] = "cd";
builtin[3] = "help";
builtin[4] = "alias";
if (signal(SIGINT, sig_handler) == SIG_ERR)
{
perror("shell");
}
for (i = 0; i < 5; i++)
{
if (_strcmp(args[0], builtin[i]) == 0)
{
switchOwnArg += i;
break;
}
}
switch (switchOwnArg)
{
case 1:
free(args);
args = NULL;
free(line);
line = NULL;
exit(0);
case 2:
chdir(args[1]);
return (1);
case 3:
return (1);
case 4:
return (1);
default:
shell_run(args, line);
return (0);
}
return (0);
}
