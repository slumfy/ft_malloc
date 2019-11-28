#include "string.h"
#include "ft_malloc.h"

int main()
{
	char *test;
 test =  (char*)malloc(10);
	strcpy(test, "testing");
	printf("%s",test);
}
