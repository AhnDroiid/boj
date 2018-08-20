#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int tc;
int N,K,W;
int cost[1001];
int dp[1001];
bool rule[1001][1001];
int indegree[1001];
//int ccount = 0;
int solve(int to)
{
	//ccount++;
	if(indegree[to] == 0) return cost[to];
	if(dp[to] != -1) return dp[to];
	int ret = -1;
	int base = cost[to];
	for(int i =1; i<=N; i++)
	{
		if(i != to)
		{
			if(rule[i][to] == 1)
			{
				ret = max(ret,base+solve(i));
			}
		}
	}
	dp[to] = ret;
	//printf("ret : %d\n",ret);
	return ret;
}
int main(void)
{
	
	scanf("%d",&tc);
	for(int i =0; i<tc; i++)
	{
		scanf("%d %d",&N,&K);
		memset(indegree,0,sizeof(int) * 1001);
		memset(dp,-1,sizeof(int) * 1001);
		for(int j = 1; j<=N; j++)
		{
			scanf("%d",&cost[j]);
			memset(rule[j],0,sizeof(bool) * 1001);
		}
		int a,b;
		for(int m = 1; m<=K; m++)
		{
			
			scanf("%d %d",&a,&b);
			rule[a][b] = 1;
			indegree[b]++;
		}
		scanf("%d",&W);
		printf("%d\n",solve(W));
	}
//	printf("count : %d\n",ccount);
	
	return 0;
}

