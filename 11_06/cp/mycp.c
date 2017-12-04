#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SZ_BUF 100

// source, dest
int main(int argc, char * argv[]){

	int fd_in;
	int fd_out;
	char buf[SZ_BUF];
	int nb;

	fd_in = open(argv[1],O_RDONLY);
	fd_out = open(argv[2],O_CREATE);

	if(fd_in == -1 || fd_out == -1)
	{
		perror("Error : ");
		exit(0);
	}

	while(nb = read(fd_in,buf,SZ_BUF))
	{
		write(fd_out, buf, nb);	
	}

	close(fd_in);
	close(fd_out);

	return 0;

}
