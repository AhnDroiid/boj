#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int sum[301] = {0};
int arr[301];
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}
	sum[0] = arr[0];
	for(int i=1; i<n;i++)
	{
		sum[i] = arr[i] + max(sum[i-3] + arr[i-1],sum[i-2]);
	}
	printf("%d\n",sum[n-1]);
	return 0;
}
