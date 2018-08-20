#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,k;
bool possible = false;
int dp[10001];
int cost[101];
int sol;
int solve(int num)
{
	if(num < 0) return 987654321;
	if(num == 0)
	{
		possible = true;
		return 0;
	}
	if(dp[num] != -1) return dp[num];
	int result = 987654321;
	
	for(int i = 1; i<=n; i++)
	{
		//printf("result : %d\n",result);
		result = min(result,1+solve(num-cost[i]));
	}
	dp[num] = result;
	return result;
}
int main(void)
{

	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i<=n; i++)
	{
		scanf("%d",cost+i);
	}
	sort(cost+1,cost+n+1,greater<int>());
	sol = solve(k);
	if(possible)
		printf("%d\n",sol);
	else printf("-1\n");

	return 0;
}

