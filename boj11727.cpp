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
int dp[1001][1001];
const int INF = -987654321;
const int mod = 10007;
int solve(int a, int b)
{
	if(a == 0 && b == 0) return 1;
	if(a < 0 || b < 0) return INF;
	if(dp[a][b] != -1) return dp[a][b];
	int result = 0;
	if(a-2 >= 0 && b-2 >= 0) result += (2 * solve(a-2,b-2));
	result %= mod;
	result = max(result,0);
	if(a-1 >= 0 && b-1 >= 0) result += solve(a-1,b-1); 
	result %= mod;
	result = max(result,0);
	dp[a][b] = result;
	return result % mod;
	
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(n,n));



	return 0;
}

