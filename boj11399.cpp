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
int p[1001];
int main(void)
{
	scanf("%d",&n);
	for(int i =1; i<=n; i++)
	{
		scanf("%d",p+i);
	}	
	sort(p+1,p+n+1);
	int sum = 0;
	int sol = 0;
	for(int i = 1; i <=n; i++)
	{
		sum += p[i];
		sol+=sum;
	}
	printf("%d\n",sol);

	return 0;
}

