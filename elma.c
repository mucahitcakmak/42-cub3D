#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("main.c", O_RDONLY, 0777);
	pntf("%d\n",fd);

}