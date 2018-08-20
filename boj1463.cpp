#include <iostream>
#include <cstdio>
#include <algorithm>
const int MAX = 1000001;
int input;
int dp[MAX];
int func(int n);
using namespace std;

int main(void)
{
	scanf("%d",&input);
	fill(dp,dp+MAX,-1);
	printf("%d\n",func(input));
	return 0;
}

int func(int n)
{
	if(n == 1) return 0;
	
	if(dp[n] != -1) return dp[n];
	int result = func(n-1) + 1;
	if(n%3 == 0) result  = min(result,func(n/3) + 1);
	if(n%2 == 0) result = min(result,func(n/2) + 1);
	dp[n] = result;
	return result;
}


