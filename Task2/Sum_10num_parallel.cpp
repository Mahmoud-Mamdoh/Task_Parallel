#include <stdio.h>
#include <omp.h> 
#include <iostream>

int main()
{
	int sum1=0,sum2=0,num[10]={1,2,1,3,1,1,1,0,1,1},i=0,j=0,id=0;
	printf("Enter 10 numbers\n");
	
	for(i=0;i<10;i++)
	{
		printf("Enter number  %d : ",i+1);
		scanf("%d",&num[i]);
		printf("\n");
	}
	

	#pragma omp parallel num_threads(2)
  {
  int id = omp_get_thread_num();
  if(id==0)
    for(i=0;i<5;i++)  sum1+=num[i];
  else
    for(i=5;i<10;i++)  sum2+=num[i];  
  }	
	
	printf("Sum 5 num in thread 1  : %d  \nSum 5 num in thread 2  : %d" ,sum1,sum2);
	
	return 0;	
}
