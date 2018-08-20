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
int n;
const int mod = 10007;
int solve(int a, int b)
{
	if(a < 0 || b < 0) return 0;
	if(a == 0 &&  b == 0) return 1;
	if(a == 0 &&  b == 1) return 0;
	if(a == 1 &&  b == 0) return 0;
	
	if(dp[a][b] != -1) return dp[a][b];
	int result = 0;
	if(a-2 >= 0 && b-2 >= 0) result += solve(a-2,b-2) % mod;
	if(a-1 >= 0 && b-1 >= 0) result += solve(a-1,b-1) % mod;
	dp[a][b] = result % mod;
	return result % mod;
}

int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(n,n) % mod);
	
	

	return 0;
}

