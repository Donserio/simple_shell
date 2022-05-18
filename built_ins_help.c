#include "shell.h"

/**
 * _realloc -reallocate memory
 * @ptr: pointer pointing to the memory
 * 
 * Return: the pointer pointing to the memory address
 */
void *_realloc(void *ptr, size_t originalLength, size_t newLength)
{

   if (newLength == 0)
   {
      free(ptr);
      return NULL;
   }
   else if (!ptr)
   {
      return malloc(newLength);
   }
   else if (newLength <= originalLength)
   {
      return ptr;
   }
   else
   {
      assert((ptr) && (newLength > originalLength));
      void *ptrNew = malloc(newLength);
      if (ptrNew)
      {
          memcpy(ptrNew, ptr, originalLength);
          free(ptr);
      }
      return ptrNew;
    }
}
