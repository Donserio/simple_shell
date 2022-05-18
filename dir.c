#include "shell.h"

/*lsca*/
int c_dir(char **input)
{
	char *args = input[1];
	if (!args || !strcmp(args, "~") || !strcmp(args, "$HOME") || !strcmp(args, "--"))
		return (cd_home());
	else if (!strcmp(args, "-"))
		return (cd_back());
	else if (!strcmp(args, "."))
		return (cd_curr());
	else if (!strcmp(args, ".."))
		return (cd_parent());
	else
		return (cd_path(input[1]));
}

/**
 * cd_home - changes to home directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_home(void)
{
	char *p_cwd, *home;
	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	p_cwd = strdup(cwd);

	home = _getenv("HOME");
	printf("%s\n", home);

	if (home == NULL)
	{
		setenv("OLDPWD", p_cwd, 1);
		free(p_cwd);
		return (1);
	}

	if (chdir(home) == -1)
	{
		free(p_cwd);
		t_error("Cannot go home\n");
		return (1);
	}

	write(STDOUT_FILENO, home, strlen(home));
	write(STDOUT_FILENO, "\n", 1);

	setenv("OLDPWD", p_cwd, 1);
	setenv("PWD", home, 1);
	free(p_cwd);
	return (1);
}

/**
 * cd_back - changes to the previous directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_back(void)
{
	char cwd[PATH_MAX];
	char *p_cwd, *p_oldcwd, *cp_cwd, *cp_oldcwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);

	p_oldcwd = _getenv("OLDPWD");

	if (p_oldcwd == NULL)
		cp_oldcwd = cp_cwd;
	else
		cp_oldcwd = strdup(p_oldcwd);

	setenv("OLDPWD", cp_cwd, 1);

	if (chdir(cp_oldcwd) == -1)
		setenv("PWD", cp_cwd, 1);
	else
		setenv("PWD", cp_oldcwd, 1);

	p_cwd = _getenv("PWD");

	write(STDOUT_FILENO, p_cwd, strlen(p_cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_cwd);
	if (p_oldcwd)
		free(cp_oldcwd);

	chdir(p_cwd);
	return (1);
}

/**
 * cd_curr - changes to the current directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_curr(void)
{
	char cwd[PATH_MAX];
	char *cp_cwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);

	setenv("PWD", cp_cwd, 1);

	write(STDOUT_FILENO, cp_cwd, strlen(cp_cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_cwd);
	return (1);
}

/**
 * cd_parent - changes to the current directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_parent(void)
{
	char cwd[PATH_MAX];
	char *dir, *cp_cwd, *cp_strtok_cwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);
	setenv("OLDPWD", cp_cwd, 1);

	if (!strcmp("/", cp_cwd))
	{
		free(cp_cwd);
		return (1);
	}

	cp_strtok_cwd = cp_cwd;
	str_reverse(cp_strtok_cwd);

	cp_strtok_cwd = strtok(cp_strtok_cwd, "/");
	if (cp_strtok_cwd != NULL)
	{
		cp_strtok_cwd = strtok(NULL, "\0");

		if (cp_strtok_cwd != NULL)
			str_reverse(cp_strtok_cwd);
	}

	if (cp_strtok_cwd != NULL)
	{
		chdir(cp_strtok_cwd);
		setenv("PWD", cp_strtok_cwd, 1);
	}
	else
	{
		chdir("/");
		setenv("PWD", "/", 1);
	}

	write(STDOUT_FILENO, cp_strtok_cwd, strlen(cp_strtok_cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_cwd);
	return (1);
}

/**
 * cd_path - changes to a directory given
 * by the user
 *
 * @dir: directory to change to
 * Return: no return
 */
int cd_path(char *dir)
{
	char cwd[PATH_MAX];
	char *cp_cwd, *cp_dir;

	getcwd(cwd, sizeof(cwd));

	if (chdir(dir) == -1)
		t_error("Cannot change to the given directory\n");

	cp_cwd = strdup(cwd);
	setenv("OLDPWD", cp_cwd, 1);

	cp_dir = strdup(dir);
	setenv("PWD", cp_dir, 1);

	write(STDOUT_FILENO, cp_dir, strlen(cp_dir));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_cwd);
	free(cp_dir);

	chdir(dir);
	return (1);
}
