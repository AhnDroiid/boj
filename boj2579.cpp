#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int stair;


int arr[301];
int dp[301];

int f(int n,int state) //state 0 : ½ÃÀÛ ÁöÁ¡, state 1: 1Ä­ ¿Ã¶ó¿È, state2:  2Ä­ ¿Ã¶ó¿È 
{
	if(n==stair) return arr[n];
	if(n>stair) return 0;
	if(dp[n] != -1) return dp[n];
	int result;
	if(state == 0 || state == 2) 
	{
		int result1;
	//	printf("not one \n");
	//	printf("n: %d\n",n);
		if(n==0)
			result1 = max(arr[n]+f(n+1,0),arr[n]+f(n+2,0));
		else
			result1 = max(arr[n]+f(n+1,1),arr[n]+f(n+2,2));
		result = result1;		
	}
	else
	{
	//	printf("one!\n");
		result = arr[n]+f(n+2,2);
	}
	if(result != (arr[n] + arr[n+1] + arr[n+2]) )
		dp[n] = result;
	printf("result: %d, n: %d\n",result,n);
	return result;
}
int main(void)
{
	scanf("%d",&stair);
	arr[0] = 0;
	dp[stair] = arr[stair];
	for(int i=1; i<=stair; i++)
		scanf("%d",arr+i);
	memset(dp,-1,sizeof(int) * 301);
	printf("%d\n",f(0,0));
/*	for(int i=0; i<=stair; i++)
		printf("%d ",dp[i]);
*/	
	return 0;
}

