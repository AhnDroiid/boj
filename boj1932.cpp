#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
int arr[501][501];
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=i; j++)
		{	
			scanf("%d",&arr[i][j]);
		}
		if(i != 1)
		{
			arr[i][1] += arr[i-1][1];
			for(int k = 1; k<i-1; k++)
			{
				arr[i][k+1] += max(arr[i-1][k],arr[i-1][k+1]);
			}
			arr[i][i] += arr[i-1][i-1];
		}
	}
	int maxx = -1;
	for(int i =1; i<=n; i++)
	{
		if(maxx < arr[n][i]) maxx = arr[n][i];
	}
	printf("%d\n",maxx);

	return 0;
}

