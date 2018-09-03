#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int result = 0;
int n,m;
int data[1001][1001];
int visited[1001];
void dfsVisit(int src)
{
	for(int i = 1; i <=n; i++)
	{
		if(visited[i])
			continue;
		if(data[src][i] == 1)
		{
			visited[i] = 1;
			dfsVisit(i);
		}
	}
}
void dfs(void)
{
	
	for(int i = 1; i <=n; i++)
	{
		if(visited[i])
			continue;
		else
		{
			result++;
			visited[i] = 1;
			dfsVisit(i);
		}
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		data[a][b] = 1;
		data[b][a] = 1;
	}
	dfs();
	printf("%d\n",result);
	return 0;
}

