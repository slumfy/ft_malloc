#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main()
{
printf("pagesize = %ld\n", sysconf(_SC_PAGE_SIZE));
	size_t	length;
	int	prot;
	int	flags;
	char *test;
	length = sysconf(_SC_PAGE_SIZE);
	prot = PROT_READ | PROT_WRITE | PROT_EXEC;
	flags = MAP_ANON | MAP_PRIVATE;

	test = mmap(0,length,prot,flags,0,0);
	strcpy((char*)test, "hello world\n");
	printf("%s",(char*)test);
}
