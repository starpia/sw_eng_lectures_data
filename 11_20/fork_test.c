#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void checkpid(char *id)
{
	printf("%s, MY PID : %d\n",id,(int)getpid());
	printf("%s, MY PPID : %d\n",id,(int)getppid());
	return;
}

int main(void)
{

	pid_t child_pid = fork();
	int child_status = 1206;
	int status = 0;

	if(child_pid == -1)
	{
		perror("fork error! : ");
		exit(0);
	}
	else if(child_pid == 0)
	{
		checkpid("child");
		exit(child_status);
	}
	else
	{
		checkpid("parent");
		wait(&status);
		printf("status : %d %d\n",status,WEXITSTATUS(status));
	}

	exit(0);

}
