#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 5

void * printHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	system("date ");
	printf("%ld \n ",tid);
	
	pthread_exit(NULL);
}

int main(int argc , char *argv[])
{
	pthread_t thread[NUM_THREADS];
	int rc;
	long t;
	for(t = 0; t < NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n",t);
		rc = pthread_create(&thread[t],NULL,printHello,(void *)t);
		if(rc)
		{
			printf("Error; return code from pthread_create is %d\n",rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
