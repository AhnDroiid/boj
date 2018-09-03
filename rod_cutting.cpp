#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int cost[3001];
int dp[3001];
int solve(int num)
{
	if(num == 0) return 0;
	if(num == 1) return cost[1];
	if(dp[num] != -1) return dp[num];
	int result = -1;
	for(int i = 1; i<=num; i++)
	{
		result = max(result,cost[i] + solve(num-i));
	}
	dp[num] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		scanf("%d",&cost[i]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(n));
 	return 0;
}

