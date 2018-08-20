#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int v[301][301];
int func(int q ,int w, int e, int r)
{
	int sum = 0;
	for(int s = q; s<=e; s++)
	{
		for(int d = w; d<=r; d++)
		{
			sum+=v[s-1][d-1];
		}
	}
	return sum;
}
int n,m,i,j,k;
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int a = 0; a<n; a++)
	{
		for(int b= 0; b<m; b++)
		{
			scanf("%d",&v[a][b]);
		}
	}
	scanf("%d",&k);
	for(int c = 0; c<k; c++)
	{
		int t1,t2,t3,t4;
		scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
		printf("%d\n",func(t1,t2,t3,t4));
	}


	return 0;
}

