#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int N,K;
int coin[11];
int sol = 0;
int main(void)
{
	scanf("%d %d",&N,&K);
	for(int i = 1; i<=N; i++)
		scanf("%d",coin+i);
	
	int idx = N;
	
	while(K > 0)
	{
		if(coin[idx] <= K)
		{
			sol += K/coin[idx];
			K%=coin[idx];
		} 
		idx--;
	}
	printf("%d\n",sol);
	return 0;
}

