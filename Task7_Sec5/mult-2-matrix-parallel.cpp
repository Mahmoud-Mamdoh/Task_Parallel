#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
	int n=3,m=2,k=3,nThread,id,i,sum=0;
	
	
	int arr1[n][m]={{1,2},{3,4},{5,6}},
	arr2[m][k]={{1,2,3},{4,5,6}},
	arr3[n][k];

	
	
	printf("Enter Num of Threads\n");
	scanf("%d",&nThread);
	
	double t1 = omp_get_wtime();
	#pragma omp parallel num_threads(nThread)
	{
		#pragma omp for collapse(3)
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		for(int f=0;f<m;f++)
		arr3[i][j]+=arr1[i][f]*arr2[f][j];
		
	}
	
	double time = omp_get_wtime() - t1;
	printf("Result is :\n", time);
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			printf("%d\t", arr3[i][j]);
			printf("\n");
		}
		
		
	printf("\nTime Is %f \n", time);
	return 0;
}
