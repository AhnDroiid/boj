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
typedef unsigned long long ull;
const int mod = 1000000000;
ull ccount = 0;
ull dp[101][10];
ull solve(int val,int pos)
{
	if(val < 0 || val >=10) return 0;
	if(dp[pos][val] != -1) return dp[pos][val];
	if(pos == n) return 1;
	ull result = 0;
	
	result += solve(val+1,pos+1);
	result %= mod;
	result += solve(val-1,pos+1);
	result %= mod;
	
	dp[pos][val] = result;
	return result;

}
int main(void)
{
	
	scanf("%d",&n);
	for(int i =0; i<101; i ++)
		memset(dp[i],-1,sizeof(ull) * 10);
	
	for(int i = 1; i<=9; i++)
		ccount+=solve(i,1);
	printf("%llu\n",ccount%mod);
		
	
	



	return 0;
}

