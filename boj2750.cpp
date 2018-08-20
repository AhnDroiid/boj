#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}
	sort(arr,arr+n,less<int>());
	for(int i=0; i<n; i++)
		printf("%d\n",arr[i]);
	


	return 0;
}

