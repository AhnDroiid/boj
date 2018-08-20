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
ull a,b;
ull gcd(ull c, ull d)
{
	if(c%d) return gcd(d,c%d);
	else return d;
}
ull solve(ull a, ull b)
{
	ull it = gcd(a,b);
	for(ull i = 0; i<it; i++)
		printf("1");
	printf("\n");
}
int main(void)
{
	scanf("%llu %llu",&a,&b);
	if(a > b) solve(a,b);
	else solve(b,a);



	return 0;
}

