#include "shell.h"
/**
 * sig_handler - does signals
 * @signo: a signal
 * Return: nada
 */
void sig_handler(int signo)
{
if (signo == SIGQUIT)
exit(99);
}
