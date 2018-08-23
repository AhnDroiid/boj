#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
const int mod = 1000000000;
int n,k;
int dp[201][201];
typedef unsigned long long ull;
ull solve(int num,int c)
{
	if(num < 0) return 0;
	if(num == 0) return 1;
	if(c == 1)
	{
		if(num <= n) return 1;
		return 0;
	}
	if(dp[num][c] != -1) return dp[num][c];
	ull result = 0;
	for(int i = 0; i<=n; i++)
		result += solve(num-i,c-1) % mod;
	dp[num][c] = result % mod;
	return result % mod;
}
int main(void)
{

	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof(dp));
	printf("%llu\n",solve(n,k));


	return 0;
}

