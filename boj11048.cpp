#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,m;
int v[1001][1001];
int dp[1001][1001];
int solve(int s,int d)
{
	if(s > n || d > m) return 0;
	if(dp[s][d] != -1) return dp[s][d];
	
	int result = 0;
	result = max(result,v[s][d] + solve(s+1,d));
	result = max(result,v[s][d] + solve(s,d+1));
	result = max(result,v[s][d] + solve(s+1,d+1));
	dp[s][d] = result;
	return result;
}
int main(void)
{
	scanf("%d %d",&n,&m);
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			scanf("%d",&v[i][j]);
		}
	}
	printf("%d\n",solve(1,1));

	return 0;
}

