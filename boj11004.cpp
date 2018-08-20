#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int arr[5000000];
int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}
	sort(arr,arr+n);
	printf("%d\n",arr[k-1]);



	return 0;
}

