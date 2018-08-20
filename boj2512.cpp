#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
typedef long long ll;
ll N;
ll arr[10001];
ll M;

ll sum(ll val)
{
	ll t = 0;
	for(ll i = 1; i<=N; i++)
	{
		if(arr[i] > val)
			t+= val;
		else
			t+=arr[i];
	}
	return t;
}
int main(void)
{
	scanf("%lld",&N);
	for(ll i = 1; i<=N; i++)
		scanf("%lld",arr+i);
	scanf("%lld",&M);
	
	ll left, right, mid, ans;
	
	left = 0, right = M;
	
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(sum(mid) <= M)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid-1;	
	}
	for(ll i = 1; i<=N; i++)
	{
		if(arr[i] > ans)
			arr[i] = ans;
	}
	sort(arr+1,arr+N+1);
	printf("%lld\n",arr[N]);

	return 0;
}

