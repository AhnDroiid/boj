#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int w[17][17];
int n;
const int INF = 987654321;
int dp[1<<17 + 1][17];
int solve(int cur, int last)
{
	if(cur == (1<<n)-1)
		return w[last][0] ? w[last][0] : INF;
	if(dp[cur][last] != -1) return dp[cur][last];
	
	int result = INF;
	
	for(int i = 0; i<n; i++)
	{
		if(cur & (1 << i)) continue;
		if(w[last][i] == 0) continue;
		result = min(result,solve((cur | (1 << i)),i) + w[last][i]);
	}
	dp[cur][last] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	printf("%d\n",solve(1,0));
 	return 0;
}

