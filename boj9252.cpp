#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
string src,dst;
int n,m;
int dp[1001][1001];
int solve(int Lpos,int Rpos)
{
	int flag = false;
	int i;
	if(Lpos<0 || Rpos < 0) return 0;
	if(dp[Lpos][Rpos] != -1) return dp[Lpos][Rpos];
	for(i = Rpos; i>= 0; i--)
	{
		if(dst[i] == src[Lpos])
		{ 
			flag = true;
			break;
		}
	}
	int result = -123;
	if(flag)
	{
		result = max(result,1+solve(Lpos-1,i-1));
		result = max(result,solve(Lpos-1,Rpos));
	}
	else
	{
		result = max(result,solve(Lpos-1,Rpos));
		result = max(result,solve(Lpos,Rpos-1));
		result = max(result,solve(Lpos-1,Rpos-1));
	}
	dp[Lpos][Rpos] = result;
	return result;
}
int main(void)
{

	cin >> src >> dst;
	n = src.length();
	m = dst.length();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(n-1,m-1));
	/*
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}*/
	
	deque<char> v;
	int i = n-1;
	int j = m-1;
	while(dp[i][j] != 0)
	{
		if (dp[i][j] == dp[i - 1][j]  ) {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else {
            v.push_front(src[i]);
            i--;
            j--;
        }
	}
	for(int i = 0; i<v.size(); i++)
	{	if(v[i] >='A' && v[i] <='Z')
			printf("%c",v[i]);
	}
	printf("\n");
	return 0;
}

