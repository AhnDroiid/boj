#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
int dp[10001];
int arr[101];
int n,k;
int main(void)
{

	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",arr+i);
	dp[0] = 1;
	for(int i=1; i<=n; i++)
	{
		for(int j = arr[i]; j<=k; j++)
		{
			dp[j] += dp[j-arr[i]];
		}
	}
	printf("%d\n",dp[k]);

	return 0;
}

