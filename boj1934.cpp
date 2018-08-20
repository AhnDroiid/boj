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
int gcd(int a, int b)
{
	if(a%b == 0) return b;
	else
		return gcd(b,a%b);
}
int lca(int a, int b)
{
	return (a*b) / gcd(a,b);
}
int main(void)
{
	scanf("%d",&tc);
	int a,b;
	for(int i =0; i<tc; i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",lcd(a,b));
	}



	return 0;
}

