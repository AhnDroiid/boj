#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <cmath>
using namespace std;
int n;
int tc;
int ccount;
int div(int num)
{
	int ret;
	int c = 0;
	for(int i = 1; i<=sqrt(num); i++)
	{
		ret = num / i;
		if(ret == i && num % i == 0) c += 1;
		else if(ret  != i && num % i == 0) c+=2;
	}
	return c;
}
int main(void)
{
	scanf("%d",&tc);
	for(int i = 0; i<tc; i++)
	{
		scanf("%d",&n);
		for(int j = 1; j<=n; j++)
		{
			if(div(j) % 2 != 0) ccount++;
		} 
		printf("%d\n",ccount);
		ccount = 0;
	}



	return 0;
}

