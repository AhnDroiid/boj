#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int num;
int cost[10001];
int dp[1001];
const int INF = -987654321;
int solve(int n)
{
	if(n == 0) return 0;
	if(n < 0) return INF;
	
	if(dp[n] != -1) return dp[n];
	int result = 0;
	for(int i = 1; i<=num; i++)
	{
		result = max(result,cost[i]+solve(n-i)); 
	}
	
	dp[n] = result;
	return result;
}
int main(void)
{

	scanf("%d",&num);
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i<=num; i++)
	{
		scanf("%d",cost+i);
	}
	printf("%d\n",solve(num));


	return 0;
}

