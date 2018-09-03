#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[201][201];
int val[201][201];
int n;
const int INF = 987654321;
int solve(int x, int y)
{
	if(x > n || y > n) return -1 * INF;
	if(x == n && y == n) return val[x][y];
	if(dp[x][y] != -1) return dp[x][y];
	int result = -1 * INF;
	result = max(result,val[x][y] + solve(x+1,y));
	result = max(result,val[x][y] + solve(x,y+1));
	dp[x][y] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i<=n; i++)
		for(int j =1; j<=n; j++)
			scanf("%d",&val[i][j]);
	printf("%d\n",solve(1,1));
 	return 0;
}

