#include <stdlib.h>

int main()
{
  int i;
  char *addr;

  i = 0;
  while (i < 3)
  {
   addr = (char*)malloc(1024);
   addr[0] = 42;
show_alloc_mem();
   free(addr);
   i++;
  }
  return (0);
}
