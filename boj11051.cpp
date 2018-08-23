#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;

int dp[1001][1001];
typedef unsigned long long ull;
ull n,k;
const ull mod = 10007;
ull solve(ull a, ull b)
{
	if(a == b) return 1;
	if(a == 1 || b == 0) return 1;
	ull result = 0;
	if(dp[a][b] != -1) return dp[a][b];
	result = solve(a-1,b-1) + solve(a-1,b);
	dp[a][b] = result%mod;
	return result%mod;
}
int main(void)
{
	scanf("%llu %llu",&n,&k);
	memset(dp,-1,sizeof(dp));
	printf("%llu\n",solve(n,k));
	return 0;
}

