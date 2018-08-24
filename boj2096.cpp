#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int dp[100001][3];
int v[100001][3];
int n;
int solve(int num,int idx)
{
	if(num > n) return 0;
	if(dp[num][idx] != -1) return dp[num][idx];
	
	int maks = -1;
	if(idx == 0)
	{
		maks = max(maks,v[num][idx] + solve(num+1,0));
		maks = max(maks,v[num][idx] + solve(num+1,1));
	}
	else if(idx == 1)
	{
		maks = max(maks,v[num][idx] + solve(num+1,0));
		maks = max(maks,v[num][idx] + solve(num+1,1));
		maks = max(maks,v[num][idx] + solve(num+1,2));
	}
	else
	{
		maks = max(maks,v[num][idx] + solve(num+1,1));
		maks = max(maks,v[num][idx] + solve(num+1,2));
	}
	dp[num][idx] = maks;
	return maks;
}
int msolve(int num, int idx)
{
	if(num > n) return 0;
	if(dp[num][idx] != -1) return dp[num][idx];
	int mean = 987654321;
	if(idx == 0)
	{
		mean = min(mean,v[num][idx] + msolve(num+1,0));
		mean = min(mean,v[num][idx] + msolve(num+1,1));
	}
	else if(idx == 1)
	{
		mean = min(mean,v[num][idx] + msolve(num+1,0));
		mean = min(mean,v[num][idx] + msolve(num+1,1));
		mean = min(mean,v[num][idx] + msolve(num+1,2));
	}
	else
	{
		mean = min(mean,v[num][idx] + msolve(num+1,1));
		mean = min(mean,v[num][idx] + msolve(num+1,2));
	}
	dp[num][idx] = mean;
	return mean;
}
int main(void)
{
	
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 1; i<=n; i++)
	{
		scanf("%d %d %d",&v[i][0],&v[i][1],&v[i][2]);
	}
	int m = -1;
	int x = 987654321;
	m = max(m,solve(0,0));
	m = max(m,solve(0,1));
	m = max(m,solve(0,2));
	memset(dp,-1,sizeof(dp));
	x = min(x,msolve(0,0));
	x = min(x,msolve(0,1));
	x = min(x,msolve(0,2));
	printf("%d %d\n",m,x);
	return 0;
}

