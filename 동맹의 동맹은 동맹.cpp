#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n,q;
int memo[100001];
int group_num = 1;
int val;
vector<int> sol;
bool solve(int f, int p1, int p2)
{
	if(f == 0)
	{
		if(!memo[p1] && !memo[p2])
		{
			memo[p1] = group_num++;
			memo[p2] = memo[p1];
		}
		else if(memo[p1] && memo[p2])
		{
			if(memo[p1] < memo[p2])
			{
				for(int i = 1; i<=n; i++)
					if(i != p2 && memo[i] == memo[p2])
					{
						memo[i] = memo[p1];
					}
				memo[p2] = memo[p1];
			}
			else if(memo[p1] > memo[p2])
			{
				for(int i = 1; i<=n; i++)
					if(i != p1 && memo[i] == memo[p1])
					{
						memo[i] = memo[p2];
					}
				memo[p1] = memo[p2];
			}
			
		}
		else if(memo[p1] == 0 || memo[p2] == 0)
		{
			int x = max(memo[p1],memo[p2]);
			memo[p1] = x;
			memo[p2] = x;
		}
		return false;
	}

	if(memo[p1] != 0 && memo[p2] != 0 && memo[p1] == memo[p2]) val = 1;
	else  val = 0;
	
	return true;
	
}

int main(void)
{
	scanf("%d %d",&n,&q);
	for(int i = 0; i<q; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(solve(a,b,c)) sol.push_back(val);
	}
	/*
	for(int i = 1; i<=n; i++)
		printf("%d ",memo[i]);
	printf("\n");*/
	for(int i = 0; i<sol.size(); i++)
		printf("%d\n",sol[i]);
 	return 0;
}

