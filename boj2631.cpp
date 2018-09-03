#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int v[201];
int pos[201];
int n;
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		v[i] = 1;
	for(int i = 1; i<=n; i++)
		scanf("%d",&pos[i]);
	for(int i =1; i<=n; i++)
	{
		for(int j = 1;  j<i; j++)
		{
			if(pos[i] >pos[j])
			{
				v[i] = max(v[i], v[j] + 1);
			}
		}
	}
	sort(v+1,v+n+1,greater<int>());
	printf("%d\n",n-v[1]);
	return 0;
}

