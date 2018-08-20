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
int dp[3][10001];
int val[10001];
int solve(int pos, int succ)
{
	if(pos > n) return 0;
	if(pos == n) return val[pos];
	if(dp[succ][pos] != -1) return dp[succ][pos];
	int ret = -1;
	if(succ == 1)
	{
		ret = max(ret,solve(pos+1,succ));
		ret = max(ret,val[pos]+solve(pos+1,succ+1));
		ret = max(ret,val[pos]+solve(pos+2,succ));
	}
	else
	{
		ret = max(ret, val[pos]+solve(pos+2,1));
	}
	dp[succ][pos] = ret;
	return ret;
}
int main(void)
{
	scanf("%d",&n);
	for(int i =1; i<=n; i++)
	{
		scanf("%d",val+i);
	}
	memset(dp[1],-1,sizeof(int) * 10001);
	memset(dp[2],-1,sizeof(int) * 10001);
	printf("%d\n",solve(1,1));


	return 0;
}

