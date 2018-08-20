#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

const unsigned long long mod = 1000000;
const unsigned long long p = mod/10 * 15;
unsigned long long fibo[p] = {0,1};
int main(void)
{
	unsigned long long n;
	scanf("%llu",&n);
	for(unsigned long long i=2; i<p; i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2];
		fibo[i] %= mod;
	}
	printf("%llu\n",fibo[n%p]);



	return 0;
}

