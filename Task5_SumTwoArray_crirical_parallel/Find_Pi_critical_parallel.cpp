#include <stdio.h>
#include <omp.h>

int main()
{
	int nth ,step;
	double pi,t,time,s;
	printf("Enter Step : ");
	scanf("%d",&step);
	
	s = 1.0/step;
	printf("s = %f : \n",s);
	
	printf("Enter Number Of Threads : ");
	scanf("%d",&nth);
	
	t = omp_get_wtime();
	
	#pragma omp parallel num_threads(nth)
	{
		int id = omp_get_thread_num();
		double x ,sum;
		for(int i=id;i<step;i+=nth)
		{
			x = (i*0.5) * s;
			sum +=4.0/(1+x*x);
			#pragma omp critical 
			{
			pi += sum*s;
			/*
			Here after finishing Thread task execute parallel critical
			*/
			}
		}
	
	}
    time = omp_get_wtime()-t;
	printf("Result  = %f  Time is = %f\n",pi,time);
}
	
	
	
