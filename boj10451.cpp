#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int v[1001][2];
int n;
int tc;
int visited[1001];
int solve(void)
{
	int result = 0;
	for(int i = 1; i<=n; i++)
	{
		if(visited[i]) continue;
		visited[i] = 1;
		int idx = i;
		//printf("i1 : %d\n", i);
		while(!visited[v[idx][1]])
		{
			//printf("idx : %d\n",idx);
			visited[idx] = 1;
			idx = v[idx][1];
		}
		visited[idx] = 1;
		result++;
	}
	return result;
}
int main(void)
{
	scanf("%d",&tc);
	for(int j = 0 ; j < tc ; j++)
	{
		memset(visited,0,sizeof(visited));
		scanf("%d",&n);
		for(int i = 1; i <=n; i++)
		{
			v[i][0] = i;
			scanf("%d",&v[i][1]);
		}
		printf("%d\n",solve());	
	}
	
	



	return 0;
}

