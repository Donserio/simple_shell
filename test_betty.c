#include <stdio.h>
#include <unistd>
#include "shell.h"

int dear(void)
{  
   write(2,"Hello world!", 12);
   return (1);
}  
