#include <stdio.h>
#include <unistd>
#define start main

void start() 
{  
   write(2,"Hello world!", 12);
   return (1);
}  
