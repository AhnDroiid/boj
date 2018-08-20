#include <iostream>
#include <cstdio>
#include <algorithm>

int n;
int minA;
int sol;
void f(int min)
{
	int tmp = 0;
	while(tmp <= min)
	{
		if((2*tmp +n) % 5 == 0)
		{
			sol  = (2*tmp+n) / 5;
			printf("%d\n",sol);
			return;
		}
		tmp++;
		if(tmp > min)
		{
			printf("%d\n",-1);
			return;
		}
		
	}
}

int main(void)
{
	scanf("%d",&n);
	minA = n / 3;
	f(minA);
	
	return 0;
}

