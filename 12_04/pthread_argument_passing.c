#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4
#define WORK_PER_THREAD 100

struct thread_args{
	int myid;
	long long start;
	long long end;
};

volatile long long sum[NUM_THREADS] = {0,};

void *myfuncs(void *arg)
{
	struct thread_args *in = (struct thread_args *)arg;
	/*
	for(int i=(in->start); i<(in->end); i++)
	{
		sum[in->myid]++;
	}
	*/
	sum[in->myid] = in->start + in->end;
	printf("myid = %d, start = %lld, end = %lld\n, sum = %lld\n",\
			in->myid,in->start,in->end,sum[in->myid]);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t mythread[NUM_THREADS];
	struct thread_args range[NUM_THREADS];

	for(int i=0; i<NUM_THREADS; i++)
	{
		range[i].myid = i;
		range[i].start = i*WORK_PER_THREAD + 1;
		range[i].end = (i+1)*WORK_PER_THREAD;

		if((pthread_create(&mythread[i], NULL, myfuncs, \
					&range[i])) != 0)
		{
			perror("pthread_create : ");
			exit(1);
		}
	}

	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(mythread[i], NULL);
	}

	printf("Main Done!\n");
	return 0;
}
