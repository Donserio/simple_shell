#include <stdio.h>
#include <unistd>
#include "shell.h"
#define start main

int start()
{  
   write(2,"Hello world!", 12);
   return (1);
}  
