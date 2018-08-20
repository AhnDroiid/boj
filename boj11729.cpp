#include <iostream>
#include <cstdio>
#include <cstring>

int n;

void Hanoi(int num, int start, int middle, int last)
{
	//printf("n: %d\n",num);
	if(num == 1)
	{
		printf("%d %d\n",start,last);
		return;
	}
	Hanoi(num-1,start,last,middle);
	printf("%d %d\n",start,last);
	Hanoi(num-1,middle,start,last);
	
	
}

int main(void)
{
	scanf("%d",&n);
	int data = 1;
	for(int i=0; i<n; i++)
		data*=2;
	printf("%d\n",data-1);
	Hanoi(n,1,2,3);

	return 0;
}
