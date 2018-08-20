#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n;
int v[1001];
int sol[1001];
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		scanf("%d",&v[i]);
	}
	for(int i = 1; i<=n ;i++)
	{
		sol[i] = 1;
		for(int j = 1; j<i; j++)
		{
			if(v[j] < v[i])
			{
				sol[i] = max(sol[i],sol[j]+1);
			}
		}
	}
	sort(sol+1,sol+n+1);
	printf("%d\n",sol[n]);


	return 0;
}

