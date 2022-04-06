#include <stdio.h>
#include <omp.h>


int main()
{
	int sizeArray,nThread,i,sum=0,sumTotalArray=0;
	
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
		int id = omp_get_thread_num();
		for(i = id ; i<=sizeArray ; i+= nThread )
		    arr3[i]=arr1[i]+arr2[i];
	#pragma omp critical 
	{
		sumTotalArray+=arr3[id];
        //printf(" Sum is : %d ",sumTotalArray);
	}	
		
	}
	double time = omp_get_wtime() - t1;
	
	printf("Result Of Sum Two Array is : ");
	for(i=0;i<sizeArray;i++)
	{
		printf("%d ",arr3[i]);
	}
	printf("   Sum is =  %d \n", sumTotalArray);
	
	printf("\nTime Is %f \n", time);
	return 0;
}
