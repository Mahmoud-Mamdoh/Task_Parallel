#include <stdio.h>

int main()
{
	int sum=0,num,i=0;
	for(i=0;i<10;i++)
	{
		printf("Enter number  %d :  \n",i+1);
		scanf("%d",&num);
		
		sum+=i;
	}
	
	printf("Sum 10 num is  : %d  \n" ,sum);
	
return 0;	
}
