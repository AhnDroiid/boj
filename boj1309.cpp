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
unsigned long long ull;
const int mod = 9901;
int d1[100001] = {0,1};
int d2[100001] = {0,2};
int main(void)
{


	scanf("%d",&n);
	for(int i = 2; i<=n; i++)
	{
		d1[i] = d1[i-1] + d2[i-1];
		d1[i] %= mod;
		d2[i] = d2[i-1] + d1[i-1] * 2;
		d2[i] %= mod;
	}
	printf("%d\n",(d1[n] + d2[n]) % mod);
	return 0;
}

