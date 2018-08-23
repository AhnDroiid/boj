#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int val[1001];
int cost[1001];
int n;
int main(void)
{
	scanf("%d",&n);
	for(int i =1; i<=n; i++)
	{
		scanf("%d",&val[i]);
		cost[i] = 1;
	}
	for(int i =1; i<=n; i++)
	{
		for(int j = 1; j < i; j++)
		{
			if(val[j] > val[i])
			{
				cost[i] = max(cost[j]+1,cost[i]);
			}
		}
	}

	sort(&cost[0],&cost[n+1],greater<int>());
	printf("%d\n",cost[0]);

	return 0;
}

