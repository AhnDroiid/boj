#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull dp[1001][1001];
int tc;
bool flag = false;
ull n,k,x;
string sol;
ull combination(ull a, ull b)
{
	ull t1 = 1;
	ull t2 = 1;
	if( a == b ) return 1;
	for(ull i = 1; i<=a; i++)
		t1 *= i;;
	for(ull i = 1; i<=b; i++)
		t2 *= i;
	for(ull i = 1; i<=a-b; i++)
		t2 *= i;
	return t1 / t2;
	
}
ull bino(ull a, ull b)
{
	if(a == b || b == 0) return 1;
	if(dp[a][b] != -1) return dp[a][b];
	ull result = 0;
	result = bino(a-1,b-1) + bino(a-1,b);
	dp[a][b] =result;
	return result;
}
void solve(ull sum, ull nn, ull kk,string t)
{
	if(flag) return;
	if(sum == x)
	{
		sol = t;
		flag = true;
		return;
	}
	if(nn == kk)
	{
		for(int i = 0 ; i<nn; i++)
			t  = t + "1";
		sol = t;
		flag = true;
		return;
	}
	ull zero;
	zero = bino(nn-1,kk);
	//printf("zero : %llu\n",zero);
	if(sum + zero < x)
	{
		solve(sum+zero,nn-1,kk-1,t+"1");
	}
	else
	{
		solve(sum,nn-1,kk,t+"0");
	}
	return;
}
int main(void)
{
	scanf("%d",&tc);
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i<tc; i++)
	{
		flag = false;
		scanf("%llu %llu %llu",&n,&k,&x);
		solve(0,n,k,"");
		printf("#%d ",i+1);
		cout << sol << endl;
	}
}
