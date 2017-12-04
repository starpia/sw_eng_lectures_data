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
		execl("/bin/ps","ps","-ef",NULL);
		exit(0);
	}
	else // parent
	{
		wait(NULL);
		printf("wait over!\n");
	}

	return 0;

}
