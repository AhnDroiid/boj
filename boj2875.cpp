#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int N,M,K;
int team;
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	while(K != 0 && N!=0 && M!= 0)
	{
		if(N / (2+0.0) > M) N-=1;
		else M-=1;
		K--;
		
	}
	if(N == 0 || M == 0) team = 0;
	else
	{
		if(N /2 <= M) team = N/2;
		else team = M;
	}
	printf("%d\n",team);


	return 0;
}

