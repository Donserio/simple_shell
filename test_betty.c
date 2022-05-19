#include <stdio.h>
#include <unistd.h>
#include "shell.h"
/**
 *main - A program to write to the user
 *Return: an integer 1 always
 */

int dear_betty(void)
{
        write(2, "This is our first Shell project", 32);
        return (1);
}
