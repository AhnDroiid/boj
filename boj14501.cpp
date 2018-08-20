#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int n;
int * dp;
int * t;
int * p;
int f(int e)
{
	//printf("e: %d\n",e);
	if(e == n && t[e] == 1) return p[n];
	if(e == n && t[e] != 1) return 0; 
	if(e > n) return 0;
	if(dp[e] != -1) return dp[e];
	
	int result = f(e+1);
	
	if(e+t[e]-1 <= n) result = max(result, f(e+t[e]) + p[e]);
	
	dp[e] = result;
	
	//printf("e: %d result : %d dp: %d\n",e,result,dp[e]);
	return result;
}

int main(void)
{
	scanf("%d",&n);
	dp = (int*)malloc(sizeof(int) * (n+1));
	memset(dp,-1,sizeof(int) * (n+1));
	t = (int*)malloc(sizeof(int) * (n+1));
	p = (int*)malloc(sizeof(int) * (n+1));
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&t[i],&p[i]);
	}
	printf("%d\n",f(1));
	return 0;
}
