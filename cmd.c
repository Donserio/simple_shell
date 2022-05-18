#include "shell.h"

void init_cmd(cmd_t *cmd)
{
	cmd->mode = 0;
	cmd->args = NULL;
	cmd->ready = 1;
	cmd->status = 0;
}
