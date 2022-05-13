#include <stdio.h>
#include <unistd.h>
/**
 *main - A program to write to a user
 *Return: an integer 1 always
 */

int main(void)
{
	write(2, "this is our first shell project", 59);
	return (1);
}

