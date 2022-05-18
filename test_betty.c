#include <stdio.h>
#include <unistd.h>
/**
 *main - A program to write to the user
 *Return: an integer 1 always
 */

int main(void)
{
	write(2, "This is our first Shell project", 32);
	return (1);
}
