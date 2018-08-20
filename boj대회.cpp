#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <cmath>
using namespace std;
int k;
typedef unsigned long long ull;
ull solve(int to)
{
	bool *tmp = new bool[to * 50];
	ull result = 0;
	memset(tmp,true,sizeof(bool) * (to*50));
	for(ull i =2; i<=to*50; i++)
	{
		ull mult = 2;
		if(!tmp[i]) continue;
		for(ull j = i * mult; j<=to*50; j=i*mult)
		{
				
				if(j != i && j % i == 0)
				{
					//printf("j: %d\n",j);
				 	tmp[j] = false;
				}
				mult++;
		}
	}
	ull i = 2;
	for(; i<=to*50; i++)
	{
		//printf("tmp : %d\n",tmp[i]);
		if(tmp[i])
		{
			//printf("%llu\n",i);
			 result++;
		}	
		if(result == k) break;
	}
	return i;
}
int main(void)
{
	scanf("%d",&k);
	
	printf("%llu\n",solve(k));
	return 0;
}

