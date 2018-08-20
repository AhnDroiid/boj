#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int M,N;
int ccount;
int dp[501][501];
int h[501][501];
bool check(int x, int y)
{
	if(x <= 0 || y <= 0 || x > N || y > M)	return false;
	return true;	
}
int solve(int x,int y)
{
	//printf("?n");
	//if(!check(x,y)) return 0;
	if(x == N && y == M) return 1;
	int result = 0;
	if(dp[y][x] != -1) return dp[y][x];
	if(check(x,y+1) && h[y][x] > h[y+1][x]) result += solve(x,y+1);
	if(check(x,y-1) && h[y][x] > h[y-1][x]) result += solve(x,y-1);
	if(check(x-1,y) && h[y][x] > h[y][x-1]) result += solve(x-1,y);
	if(check(x+1,y) && h[y][x] > h[y][x+1]) result += solve(x+1,y);
	dp[y][x] = result;
	return result;
	
}
int main(void)
{
	scanf("%d %d",&M,&N);
	for(int i = 1; i<=M; i++)
		memset(dp[i],-1,sizeof(int) * 501);
	for(int i = 1; i<=M; i++)
	{
		for(int j = 1; j<=N; j++)
			scanf("%d",&h[i][j]);
	}
	printf("%d\n",solve(1,1));


	return 0;
}

