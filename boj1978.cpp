#include <iostream>
#include <cstdio>
#include <cmath>

int n;
int tmp;
int sol = 0;
bool f(int num)
{
	bool t  = true;
	if(num == 1) t = false;
	for(int i=2; i<=sqrt(num); i++)
	{
		if(num % i == 0)
			t = false;
	}
	return t;
}
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&tmp);
		if(f(tmp)) sol++;
	}
	printf("%d\n",sol);
	return 0;
}
