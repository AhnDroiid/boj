#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
unsigned long long dp[91];
unsigned long long  fib(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	if(dp[n] != -1) return dp[n];
	
	unsigned long long result = fib(n-1) + fib(n-2);
	dp[n] = result;
	return result;
}
int main(void)
{
	memset(dp,-1,sizeof(unsigned long long) * 91);
	int n;
	scanf("%d",&n);
	printf("%llu\n",fib(n));


	return 0;
}

