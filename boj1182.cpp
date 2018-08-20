#include <stdio.h>
#include <stdlib.h>



int num,S;
int count = 0;
int main(void)
{
	
	scanf("%d %d",&num,&S);
	
	int * arr = (int*)malloc(sizeof(int) * num);
	
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	
	int sum = 0;
	int i,j;
	
	for(i = 1; i<(1<<num) ;i++)
	{
		for(j=0; j<num; j++)
		{
			if(i & (1 << j))
				sum+=arr[j];
		}
		if(sum == S)	
			count++;
		sum = 0;
	}
	printf("%d\n",count);
	return 0;
}



