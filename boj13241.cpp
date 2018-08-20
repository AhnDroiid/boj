#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull a, ull b)
{
	if(a%b == 0) return b;
	else
		return gcd(b,a%b);
}
ull lca(ull a, ull b)
{
	return (a*b) / gcd(a,b);
}
int main(void)
{
	//scanf("%d",&tc);
	ull a,b;
	scanf("%llu %llu",&a,&b);
	printf("%llu\n",lca(a,b));
	
	return 0;
}

