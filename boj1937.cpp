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
int dp[500][500];
int v[500][500];
bool chk(int i, int j)
{
	if(i< 0 || j < 0 || i >= n || j>= n) return false;
	return true;
}
int solve(int i,int j)
{
	//printf("i : %d, j : %d\n",i,j);
	if(i< 0 || j< 0 || i >=n || j>=n)  return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	//printf("?\n");
	int result = 1;
	if(chk(i+1,j) && v[i+1][j] > v[i][j]) result = max(result,1+solve(i+1,j));
	if(chk(i-1,j) && v[i-1][j] > v[i][j]) result = max(result,1+solve(i-1,j));
	if(chk(i,j+1) && v[i][j+1] > v[i][j]) result = max(result,1+solve(i,j+1));
	if(chk(i,j-1) && v[i][j-1] > v[i][j]) result = max(result,1+solve(i,j-1));
	dp[i][j] = result;
	//printf("result : %d\n",result);
	return result;
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i =0; i<n; i++)
	{
		for(int j = 0; j< n; j++)
			scanf("%d",&v[i][j]);
	}
	for(int i =0; i<n; i++)
	{
		for(int j = 0; j< n; j++)
			solve(i,j);
	}
	
	
	int maxx = dp[0][0];
	for(int i =0; i<n; i++)
	{
		for(int j = 0; j< n; j++)
			if(dp[i][j] > maxx) maxx = dp[i][j];
	}
	printf("%d\n",maxx);
	return 0;
}

