#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>

#define EXEC 1
#define MAXARGS 10
#define DELIM " \t\n\r\a"

extern char **environ;

typedef struct cmd_t
{
	int mode;
	char **args;
	int ready;
	int status;
} cmd_t;

void open_console(void);
void init_cmd(cmd_t *cmd);
void prompt(int status);
void t_error(char *s);
int _fork(void);
void setcmd(char *buf, cmd_t *cmd);
void runcmd(char **input, cmd_t *cmd);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t originalLength, size_t newLength)
void runcmd(char* dir, char **input, cmd_t *cmd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* ------------------ENVIRONMENT----------------- */
char *_which(char *input);
int _env(char **input);
char *_getenv(const char *name);

/* ------------------BUILTINS----------------- */
typedef struct builtins
{
	char *name;
	int (*f)(char **input);
} built_t;

int parse_builtins(char **input, cmd_t *cmd);
int exit_sh(char **input, cmd_t *cmd);
int c_dir(char **input);
/*---change directory----*/
int cd_path(char *dir);
int cd_parent(void);
int cd_curr(void);
int cd_back(void);
int cd_home(void);

/* ------------------STRING PARSER----------------- */
int _isdigit(const char *str);
char **get_toks(char *args, char *delimiter);
void str_reverse(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char **_strtok(char *line, char *delim);
int _strlen(char *s);

#endif /* SHELL_H */
