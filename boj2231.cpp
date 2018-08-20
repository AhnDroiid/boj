#include <iostream>
#include <cstring>


int n;


char tmp[8];
int sum(int in)
{
	int sum = 0;
	do
	{
		sum += in%10;
		in/=10;
	}
	while(in);
	return sum;
}
int main(void)
{
	scanf("%d",&n);
	int len = 0;
	int tmp = n;
	do{
		++len;
		 tmp/= 10;
	}while(tmp);
	
	int max = 9 * len;
	for(int i=max;i>=0; i--)
	{
		if(n - sum(n-i) == n-i)
		{
			printf("%d\n",n-i);
			return 0;
		}
	}
	printf("%d\n",0);
	return 0;
}
