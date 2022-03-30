#include <stdio.h>
#include <omp.h>

int main()
{
	int n,sum=1;
	double t1,time;
	printf("Enter Number\n");
	scanf("%d",&n);
	t1 = omp_get_wtime();
	for(int i=1;i<=n;i++)
	{
		sum*=i;
	}
	time =  omp_get_wtime()-t1;
	printf("Factorial %d is  = %d\n",n,sum);
	printf("Time is  = %f\n",time);
	return 0;
}
