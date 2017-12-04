#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{

	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork error! : ");
		exit(0);
	}
	else if(pid == 0) // child
	{
		for(int i=1; i<10000; i++)
		{
			printf("\x1b[31m %d ",i);
			fflush(NULL);
		}
		exit(0);
	}
	else // parent
	{
		for(int i=1; i<10000; i++)
		{
			printf("\x1b[32m %d ",i);
			fflush(NULL);
		}
		wait(NULL);
	}

	return 0;

}
