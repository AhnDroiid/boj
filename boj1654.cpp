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
ll K,N;
ll lan[10001];
ll check(ll val)
{
	ll sum = 0;
	for(ll i =0; i<K; i++)
	{
		sum += lan[i] / val;
	}
	return sum;
}
int main(void)
{
	scanf("%lld %lld",&K,&N);
	ll sum = 0;
	for(ll i=0; i<K; i++)
	{
		scanf("%lld",lan+i);
		sum+=lan[i];
	}
	ll left,mid,right,ret;
	ret = -1;
	left = 0;
	right = sum / N;
	while(left <= right)
	{

		mid = (left + right + 1) / 2;
		//printf("left : %lld , right : %lld , mid : %lld\n",left,right,mid);
		ll tmp = check(mid);
		if(tmp >= N)
		{
			if(ret < mid) ret = mid;
			left = mid+1;
		}
		else right = mid-1;
	}
	printf("%lld\n",ret);

	return 0;
}

