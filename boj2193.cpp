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
int arr[90];
typedef unsigned long long ull;
ull sol = 0;
ull dp[2][91];
ull solve(int size,int val)
{
	if(size == 1) return 1;
	ull result = 0;
	if(dp[val][size] != -1) return dp[val][size]; 
	if(size == n)
	{
		result += solve(size-1,0);
	}
	else
	{
		if(val == 1)
		{
			result += solve(size-1,0);
		}
		else
		{
			result += solve(size-1,0);
			result += solve(size-1,1);
		}
	}
	//printf("result : %llu\n",result);
	dp[val][size] = result;
	return result;
}
int main(void)
{
	scanf("%d",&n);
	memset(dp[0],-1,sizeof(ull) * 91);
	memset(dp[1],-1,sizeof(ull) * 91);
	dp[1][1] = 1;
	dp[0][1] = 1;
	printf("%llu\n",solve(n,1));

	return 0;
}

