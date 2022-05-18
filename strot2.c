#include "shell.h"

/**
 * exit_sh - exits the shell
 *
 * @input: vector of inputed arguments
 * @cmd: struct of global variables
 * Return: 0 on success.
 */
int exit_sh(char **input, cmd_t *cmd)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (input[1])
	{
		ustatus = atoi(input[1]);
		is_digit = _isdigit(input[1]);
		str_len = strlen(input[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			t_error("Invalid exit status");
			cmd->status = 2;
		}
		cmd->status = (ustatus % 256);
		cmd->ready = 0;
	}
	cmd->ready = 0;
	return (1);
}
