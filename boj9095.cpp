#include <iostream>

int tc;
int n;

int conb(int n)
{
	if(n <= 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	int result = conb(n-1) + conb(n-2) + conb(n-3);
	return result;
}

int main(void)
{
	scanf("%d",&tc);
	for(int i=0; i<tc; i++)
	{
		scanf("%d",&n);
		printf("%d\n",conb(n));
	}
	return 0;
}
