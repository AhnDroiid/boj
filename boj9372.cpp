#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int tc;
int n,m;
int main(void)
{
	scanf("%d",&tc);
	for(int i = 0;  i<tc; i++)
	{
		scanf("%d %d",&n,&m);
		for(int j = 0; j<m; j++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
		}
		printf("%d\n",n-1);
	}



	return 0;
}

