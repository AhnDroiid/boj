#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;

int dp[501][501];
int partial_ssum[501];
int T,K; 
int solve(int from, int to)
{
	if(from == to) return 0;
	int & ret = dp[from][to];
	if(ret != -1) return ret;
	
	ret  = 987654321;
	int entire_sum = partial_ssum[to]-partial_ssum[from-1];
	for(int i = from; i<=to; i++)
	{
		ret = min(ret,entire_sum + (solve(from,i) + solve(i+1,to)));
	}
	return ret;
}
int main(void)
{
	scanf("%d",&T);
	
	for(int i=0; i<T; i++)
	{	
		scanf("%d",&K);
		for(int  j =0; j<501; j++)
			memset(dp[j],-1,sizeof(int) * 501);
		memset(partial_ssum,0,sizeof(int) * 501);
		int tmp;
		for(int m =1; m<=K; m++)
		{
			scanf("%d",&tmp);
			partial_ssum[m] = partial_ssum[m-1] + tmp;
		}
		printf("%d\n",solve(1,K));
	}



	return 0;
}

