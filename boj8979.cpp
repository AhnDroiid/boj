#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
typedef struct __nation
{
	int gold;
	int silver;
	int bronze;
}Nation;
int n,k;
int main(void)
{
	scanf("%d %d",&n,&k);
	Nation nation[n+1];
	for(int i = 0; i<n; i++)
	{
		int nat,g,s,b;
		scanf("%d %d %d %d",&nat,&g,&s,&b);
		nation[nat].gold = g;
		nation[nat].silver = s;
		nation[nat].bronze = b;
	}
	int tg,ts,tb;
	tg = nation[k].gold;
	ts = nation[k].silver;
	tb = nation[k].bronze;
	//printf("tg : %d ts : %d tb : %d\n",tg,ts,tb);
	int r = 0;
	for(int i = 1; i<=n; i++)
	{
		if(i != k)
		{
			if(nation[i].gold > tg)
			{ 
				r++;
				continue;
			}
			if(nation[i].gold == tg)
			{
				if(nation[i].silver > ts)
				{ 
					r++;
					continue;
				}
			}
			
			if(nation[i].gold == tg && nation[i].silver == ts)
			{
				if(nation[i].bronze > tb)
				{
					 r++;
					continue;
				}
			}
		}
	}
	printf("%d\n",r+1);
 	return 0;
}

