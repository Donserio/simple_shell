#include "shell.h"

void runcmd(char* dir, char **input, cmd_t *cmd)
{
	if (input[0] == NULL)
		exit(EXIT_FAILURE);

	switch (cmd->mode)
	{
		case EXEC:
			if (execve(dir, input, NULL) < 0)
				t_error("No such file or directory\n");
			break;
	}

	exit(EXIT_SUCCESS);
}
