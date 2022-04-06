#include <stdio.h>
#include <omp.h>

int main()
{
	int n,sum=1,nThread,t1,time,i;
	printf("Enter Number\n");
	scanf("%d",&n);
	
	printf("Enter Number Of Thread\n");
	scanf("%d",&nThread);
	
	int fact[nThread];
	for(i=0;i<nThread;i++)
	   fact[i]=1;
	   
	t1 = omp_get_wtime();
	#pragma omp parallel num_threads(nThread)
	{
	    int id = omp_get_thread_num();
		for(i=id+1;i<=n;i+=nThread)
		{
		fact[id] =fact[id] * (i);
		}
	#pragma omp critical 
	{
		sum*=fact[id];
	}
	}
	
	/*for(int i=0;i<nThread;i++)
	   sum*=fact[i];*/
	   
	time =  omp_get_wtime()-t1; 
	 
	printf("Factorial %d is  = %d\n",n,sum);
	printf("Time is  = %f\n",time);
	return 0;
}
