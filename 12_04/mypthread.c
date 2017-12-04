#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

long long counter = 0;
char running = 1;

void *myfunc(void *arg)
{
	while(running == 1)
	{	
		counter++;
	}
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t pthread_pool;
	int num = 0;

	if((pthread_create(&pthread_pool,NULL,myfunc,NULL)) != 0)
	{
		perror("pthread_create! : ");
		exit(1);
	}

	for(int i=0; i<30; i++)
	{
		printf("%d : counter value = %lld\n", num, counter);
		num++;
		sleep(1);
	}

	running = 0;
	pthread_join(pthread_pool, NULL);

	return 0;
}
