#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int maks = -1;
int maksVal = - 1;
int n;
int incc[1001];
int decc[1001];
int val[1001];
void LIS(int last)
{
	for(int i = 1; i<=last; i++)
	{
		for(int j = 0; j<i; j++)
		{
			if(val[i] > val[j])
			{
				incc[i] = max(incc[i],incc[j] + 1);
			}
		}
	}
}
int LDS(int start)
{
	decc[start-1] = 0;
	for(int i = start; i<=n; i++)
		decc[i] = 1;
	for(int i = start; i<=n; i++)
	{
		for(int j = start-1; j<i; j++)
		{
			if(val[i] < val[j])
			{
				decc[i] = max(decc[i], decc[j] + 1);
			}
		}
	}
	sort(&decc[start],&decc[n+1],greater<int>());
	return decc[start];
}
int main(void)
{
	for(int i = 1; i<=1000; i++)
	{
		incc[i] = 1;
		decc[i] = 1;
	}
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		scanf("%d",&val[i]);
	LIS(n);
	for(int i = 1; i <=n; i++)
	{
		LDS(i);
		maks = max(maks,incc[i]+decc[i]-1);
		
	}
	printf("%d\n",maks);
 	return 0;
}

