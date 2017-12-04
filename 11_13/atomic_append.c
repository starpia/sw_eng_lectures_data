#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	int fd;

	if ( argc == 3 )
	{
		fd = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 0666);
		
		for(int i=0; i<atoi(argv[2]); i++)
		{
			if((int)write(fd, "A", 1) < 1)
			{
				close(fd);
				exit(0);
			}
		}
	}
	else if( argc == 4 && !strcmp(argv[3],"x"))
	{
		fd = open(argv[1], O_RDWR | O_CREAT, 0666);

		for(int i=0; i<atoi(argv[2]); i++)
		{
			lseek(fd, 0, SEEK_END);
			write(fd, "A", 1);
		}
	}

	close(fd);
	return 0;

}
