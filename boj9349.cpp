#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,k;
int tc;
int main(void)
{
	scanf("%d",&tc);
	for(int i =0 ;i<tc; i++)
	{
		scanf("%d %d",&n,&k);
		
		printf("%d\n",(n-k)/(k-1));
		
	}


	return 0;
}

