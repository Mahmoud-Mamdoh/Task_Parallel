#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
	int sizeArray,nThread,f=0,i,sum=0;
	
	printf("Enter Size of Array : \n");
	scanf("%d",&sizeArray);
	
	int arr1[sizeArray],arr2[sizeArray],arr3[sizeArray];
	
	printf("Enter Element Array 1 \n");
	for(i=0;i<sizeArray;i++)
	{
		printf("Enter Element %d : \n",i+1);
		scanf("%d",&arr1[i]);
	}
	
	
	printf("Enter Element Array 2 \n");
	for(i=0;i<sizeArray;i++)
	{
		printf("Enter Element %d : \n",i+1);
		scanf("%d",&arr2[i]);
	}
	
	
	printf("Enter Num of Threads\n");
	scanf("%d",&nThread);
	
	double t1 = omp_get_wtime();
	#pragma omp parallel num_threads(nThread) 
	{
		
		#pragma omp for 
        for(int i=0;i<sizeArray;i++)
        arr3[i] = arr1[i]+arr2[i];
        
        #pragma omp for reduction(+:sum)
        for(int i=0;i<sizeArray;i++)
        sum = sum + arr3[i];
		
		
	//	printf("sum =  %d : \n",sum);
	}
	double time = omp_get_wtime() - t1;
	
	printf("Result Of Sum Two Array is : ");
	for(int i=0;i<sizeArray;i++)
	printf("%d ",arr3[i]);
	printf("\nSum is  : %d\n",sum);
	printf("\nTime Is %f \n", time);
	return 0;
}
