#include "shell.h"

void setcmd(char *buf, cmd_t *cmd)
{
	if (!buf[0])
		exit(EXIT_FAILURE);

	cmd->mode = EXEC;
	// _scan(buf, delimiter);
}
