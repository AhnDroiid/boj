#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;
ll N;
ll K;
ll s[2*100000];
ll sum(ll val)
{
	return val*(val+1) / 2;
}
int main(void)
{
	scanf("%lld",&N);
	scanf("%lld",&K);
	int flag = 0 ;
	ll line;
	ll stdd = sum(N);
	memset(s,0,sizeof(ll) * 200000);
	for(ll i = 1; i<=N; i++)
	{
		s[i] = s[i-1] + i;
	}
	for(ll i = N+1; i<=2*N-1; i++)
	{
		s[i] = s[i-1] + (2*N-i);
	}
	for(ll i = 1; i<=2*N-1; i++)
	{
		if(K <= stdd && K <= s[i])
		{
			flag = 1;
			line = i;
			break;
		}
		if(K > stdd && K <= s[i])
		{
			flag = 2;
			line = i;
			break;
		}
	}
	ll x,y;
	if(flag == 1)
	{
		x = ceil(((K - s[line-1])/(2+0.0)));
		y = (line + 1) - x;
	}
	else if(flag == 2)
	{
		x = ceil((K - s[line-1])/(2+0.0)) + 1 ; 
		y = (line+1) - x;
	}
	printf("%lld\n",x*y);
	return 0;
}

