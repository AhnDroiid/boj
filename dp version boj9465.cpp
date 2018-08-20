#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAX = 1000000;
using namespace std;

int dp[MAX][3];
int value[2][MAX];
int tc;
int n;
int sticker(int c,int status);
int main(void)
{
	scanf("%d",&tc);
	for(int t = 0; t< tc; t++)
	{
		scanf("%d",&n);
		for(int i =0; i<2; i++)
		{
			for(int j=0; j<n; j++)
				scanf("%d",&value[i][j]);
		}
		for(int i=0; i< n; i++)
			for(int j=0; j<3; j++)
				dp[i][j] = -1;
		printf("%d\n",sticker(0,0));
	}	
}
int sticker(int c,int status)
{
	if(c == n) return 0;
	if(dp[c][status] != -1) return dp[c][status];
	int result = sticker(c+1,0);
	if(status != 1) result = max(result,sticker(c+1,1) + value[0][c]);
	if(status != 2) result = max(result,sticker(c+1,2) + value[1][c]);
	dp[c][status] = result;
	return result;
}
