#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4 
#define MAX_NUM 50000

volatile int cnt = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *myfuncs(void *arg)
{
	struct thread_args *_arg = (struct thread_args *)arg;
	int local_cnt = 0;

	for(int i=0; i<MAX_NUM; i++)
	{
		local_cnt++;
	}

	pthread_mutex_lock(&mutex);
	cnt = cnt + local_cnt;
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	
	for(int i=0; i<NUM_THREADS; i++)
	{
		if(pthread_create(&threads[i], NULL, myfuncs, NULL) != 0)
		{
			perror("pthread_create : ");
			exit(1);
		}
	}

	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	printf("cnt = %d\n",cnt);
	
	return 0;
}
