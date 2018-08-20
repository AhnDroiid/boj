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
int partial[100001];
int** dp;
int solve(int s, int e)
{
	int patial = partial[e] - partial[s-1];
	if(s == e) return patial;
	int &ret = dp[s][e];
	if(ret != -1) return dp[s][e];
	ret = max(ret,patial);
	for(int i = 0; i<(e-s); i++)
	{
		ret = max(ret,solve(s,s+i));
		ret = max(ret,solve(s+i+1,e));
	}
	return ret;
	
}
int main(void)
{
	scanf("%d",&n);
	memset(partial,0,sizeof(int) * 100001);
	/*dp = (int**)malloc(sizeof(int*) * (n+1));
	
	for(int i =0; i<=n; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * (n+1));
		memset(dp[i],-1,sizeof(int) * (n+1));
	}*/
	int tmp;
	for(int i= 1; i<=n; i++)
	{
		scanf("%d",&partial[i]);
	}
	
	int sum[100001];
	memset(sum, 0, sizeof(int) * 100001);
	int tp = partial[0];
	sum[0] = 0;
	int ret = -10000;
	for(int i = 1; i <=n; i++)
	{
		sum[i] = max(sum[i-1]+partial[i] , partial[i]);
		ret = max(ret, sum[i]);
	}
	
	printf("%d\n",ret);
	
	free(dp);

	return 0;
}

