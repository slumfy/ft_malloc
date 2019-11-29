#include "string.h"
#include "ft_malloc.h"

int main()
{
	char *test;
	char *test2;
 test =  (char*)malloc(1);
 test2 = (char*)malloc(20);
 test2 = (char*)malloc(1024);
 test2 = (char*)malloc(4096);
	show_alloc_mem();
}
