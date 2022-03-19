#include <stdio.h>
#include <omp.h> 
#include <iostream>

int main()
{
	int n,m ,i;
	printf("Enter Matrix Size\n");
	scanf("%d",&n);
	
	int arr1[n],arr2[n],sum[n];
	
	printf("Enter Element Matrix 1\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr1[i]);
	
	printf("Enter Element Matrix 2\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr2[i]);

    double t1 = omp_get_wtime();
	for(i=0;i<n;i++)
	sum[i] = arr1[i]+arr2[i];
	double time = omp_get_wtime()-t1;
	
	printf("Sum of Two Matrix is :");
	for(i=0;i<n;i++)
	printf("%d ",sum[i]);
	
	printf("\nTime Is %f \n", time);
	return 0;	
}
