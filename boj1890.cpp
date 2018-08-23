#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n;
typedef unsigned long long ull;
ull dp[101][101];
ull val[101][101];
ull solve(int f,int t)
{
	if(val[f][t] == 0 && (f!=n || t!=n)) return 0;
	if(f == n && t == n) return 1;
	if(dp[f][t] != -1) return dp[f][t];
	ull result = 0;
	if(f+val[f][t] <= n) result += solve(f+val[f][t],t);
	if(t+val[f][t] <= n) result += solve(f,t+val[f][t]);
	dp[f][t] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		for(int j = 1 ; j<=n; j++)
			scanf("%llu",&val[i][j]);
	memset(dp,-1,sizeof(dp));
	printf("%llu\n",solve(1,1));

	return 0;
}

