#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){

	pid_t result = -1;
	pid_t parent_result = -1;
	//int result_t = -1;

	result = getpid();
	parent_result = getppid();

	printf("this process's id is %ld\n",(long)result);
	printf("this process's parent process's id is %ld\n",(long)parent_result);

}
