#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
	
	int a[5]={1,2,3,4,5},
	b[5]={6,7,8,9,10},
	c[5],d[5],nThread,j=0;

	printf("Enter Num of Threads\n");
	scanf("%d",&nThread);
	
	double t1 = omp_get_wtime();
	#pragma omp parallel num_threads(nThread)
	{
		#pragma omp sections
		{
			#pragma omp section
				for(int i=0;i<5;i++)
				{
					c[i] = a[i] * a[i];
					printf("Thread Num of (a * a) = %d  i = %d\n",omp_get_thread_num(),i);
				}
		
		    #pragma omp section
				for(int i=4;i>=0;i--)
				{
					d[j++] = b[i];
					printf("Thread Num of (inverse b) = %d  i = %d\n",omp_get_thread_num(),i);
				}
				
		}
		
		
	}
	
	double time = omp_get_wtime() - t1;
	printf("Result a * a is :\n");
	for(int i=0;i<5;i++)
		{
			printf("%d\t", c[i]);
			
		}
		printf("\n");
	printf("Result inverse matrix b is :\n");
	for(int i=0;i<5;i++)
		{
			printf("%d\t", d[i]);
		}
		
	printf("\nTime Is %f \n", time);
	return 0;
}
