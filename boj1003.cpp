#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

int tc;
int n;
int * dp;
int * onedp;
int * twodp;
int sol1 = 0;
int sol2 = 0;
int fibo(int n)
{
	//printf("n: %d\n",n);
	if(n == 0)
	{ 
		//printf("0\n");
		sol1++;
		return 0;
	}
	if(n == 1)
	{
		//printf("1\n");
		sol2++;
		return 1;
	} 
	if(onedp[n] != -1) sol1+=onedp[n];
	if(twodp[n] != -1) sol2+=twodp[n];
	if(dp[n] != -1) return dp[n]; 
	int result = fibo(n-1) + fibo(n-2);
	dp[n] = result;
	onedp[n] = sol1;
	twodp[n] = sol2;
	return result;
}
int main(void)
{
	scanf("%d",&tc);
	for(int i=0;i<tc; i++)
	{
		scanf("%d",&n);
		dp = new int[n+1];
		onedp = new int[n+1];
		twodp = new int[n+1];
		memset(dp,-1,sizeof(int) * (n+1));
		memset(onedp,-1,sizeof(int) * (n+1));
		memset(twodp,-1,sizeof(int) * (n+1));
		fibo(n);
		printf("%d %d\n",sol1,sol2);
		sol1 = 0 , sol2 = 0;
		delete(dp);
		delete(onedp);
		delete(twodp);
	}
	return 0;
}
