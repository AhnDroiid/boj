#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int dp[1001];
int val[1001];
const int big = 987654321;
int solve(int num)
{
	
	if(num > n-1) return big;
	if(num == n-1) return 0;
	if(dp[num] != -1) return dp[num];
	int result = big;
	int jump =  val[num];
	for(int i = 1; i<=jump; i++)
	{
		result = min(result,1+solve(num+i));
	}
	dp[num] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i<n; i++)
	{
		scanf("%d",&val[i]);
	}
	int tmp = solve(0);
	if(tmp == big) printf("-1\n");
	else printf("%d\n",tmp);	
 	return 0;
}

