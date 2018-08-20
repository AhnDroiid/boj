#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
int n;
int dp[1001][3];
int arr[1001][3];

int solve(int color,int num)
{
	if(num == 0)
	{
		return 0;
	}
	if(color != -1 && dp[num][color] != -1)
	{
		return dp[num][color];
	}
	
	int result = 987654321;
	for(int i=0; i<3; i++)
	{
		//printf("num : %d\n",num);
		if(i == color) continue;
		result = min(result,arr[num][i]+solve(i,num-1));
	}
	if(num == n) return result;
	else 
	{
		dp[num][color] = result;
		return result;
	}
}
int main(void)
{

	scanf("%d",&n);
	for(int i=0; i<1001; i++)
		for(int j =0; j<3; j++)
			dp[i][j] = -1;
	for(int i = 1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
			scanf("%d",&arr[i][j]);
	}
	printf("%d\n",solve(-1,n));

	
	return 0;
}

