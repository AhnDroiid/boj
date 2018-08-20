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
int arr[1000001];

int main(void)
{

	scanf("%d",&n);
	memset(arr,-1,sizeof(int) * 1000001);
	int st;
	scanf("%d",&st);
	for(int i = 1; i<n; i++)
	{
		int a;
		scanf("%d",&a);
		arr[a] = a;
	}
	int length = 1;
	
	for(int i = 1; i<n; i++)
	{
		if(arr[st+i] != -1) length++;
	}
	printf("%d\n",length);
	


	return 0;
}

