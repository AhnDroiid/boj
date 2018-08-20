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
int N,M;
int dp[30][30];
int solve(int l, int r)
{
	if(l == 0) return 1;
	if(l == r) return 1;
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];
	int result;
	result = solve(l-1,r-1) + solve(l,r-1);
	dp[l][r] = result;
	return result;
}
int main(void)
{
	scanf("%d",&tc);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i<tc; i++)
	{
		scanf("%d %d",&N,&M);
		printf("%d\n",solve(N,M));
	}
	


	return 0;
}

