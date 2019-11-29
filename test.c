#include "string.h"
#include "ft_malloc.h"

int main()
{
	char *test;
	char *test2;
	char *test3;
	char *test4;
	char *test5;
	char *test6;

	test =  (char*)malloc(1);
	test2 = (char*)malloc(20);
	test3 = (char*)malloc(1000);
	test4 = (char*)malloc(4096);
	test5 = (char*)malloc(4096);
	test6 = (char*)malloc(4096);
	free(test2);
	free(test3);
//	free(test5);
	printf("zonesize %zu \t pqgesize %zu \n", sizeof(t_zone), sizeof(t_page));
	show_alloc_mem();
}
