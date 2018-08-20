#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int N,M;
int dp[301][301];
int solve(int x, int y)
{
	//printf("%d %d \n",x,y);
	if(x==0 || y==0) return 0;
	if(x == 1 && y == 1) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	
	int result = 0;
	if(x > 1) result = 1 + solve(x-1,y) + solve(1,y);
	if(y > 1) result = 1 + solve(x,1) + solve(x,y-1);
	//printf("result : %d\n",result);
	dp[x][y] = result;
	return result;
}
int main(void)
{

	scanf("%d %d",&N,&M);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(N,M));
	//printf("%d\n",(N-1) + N*(M-1));

	return 0;
}

