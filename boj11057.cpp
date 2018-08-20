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
int arr[11];
int ccount = 0;

int main(void)
{
	scanf("%d",&n);
	if(n == 1) ccount = 10;
	else
	{
		for(int i = 1; i <=10; i++)
			arr[i] = 1;
		for(int i = 2; i<=n; i++)
		{
			for(int j = 2; j<=10; j++)
			{
				arr[j] += arr[j-1];
				arr[j] %= 10007;
			}
			
		}
		for(int j = 1; j<=10; j++)
		{
			ccount += arr[j];
			ccount %= 10007;
		}
	}
	printf("%d\n",ccount);
}
