#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4 
#define MAX_NUM 1000000000

struct thread_args{
	int myid;
	long long start;
	long long end;
};

volatile long long sum[NUM_THREADS] = {0,};

void *myfuncs(void *arg)
{
	struct thread_args *in = (struct thread_args *)arg;
	int i = 0;

	for(i=(in->start); i<(in->end); i++)
	{
		sum[in->myid] = sum[in->myid] + i;
	}

	if((in->myid) == (NUM_THREADS-1))
	{
		sum[in->myid] = sum[in->myid] + i;
	}
	
	printf("sum[%d]: %lld\n",in->myid,sum[in->myid]);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	struct thread_args range[NUM_THREADS];

	long long pivotNum = MAX_NUM/NUM_THREADS;
	long long total_sum = 0;

	for(int i=0; i<NUM_THREADS; i++)
	{
		range[i].myid = i;
		range[i].start = i*pivotNum;
		range[i].end = i*pivotNum + pivotNum;

		if((pthread_create(&threads[i], NULL, myfuncs, \
					&range[i])) != 0)
		{
			perror("pthread_create : ");
			exit(1);
		}
	}

	for(int i=0; i<NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}

	for(int i=0; i<NUM_THREADS; i++)
	{
		total_sum = total_sum + sum[i];
	}

	printf("total_sum = %lld\n",total_sum);
	return 0;
}
