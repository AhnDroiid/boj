#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <queue>
using namespace std;
int visited[100001];
int n,k;
queue<int> q;
int precursor[100001][2];
void func(int t)
{
	//printf("1\n");
	if(t == n)
	{
		printf("%d ",n);
		return;
	}
	func(precursor[t][0]);
	printf("%d ",t);
}
int main(void)
{
	scanf("%d %d",&n,&k);
	q.push(n);
	int depth = 0;
	for(int i = 0 ; i <=100000; i++)
		precursor[i][1] = 987654321;
	while(!q.empty())
	{
		int size = q.size();
		//printf("size: %d\n",size);
		for(int i = 0 ; i < size; i++)
		{
			int a = q.front();
			q.pop();
			//printf("a : %d , depth : %d\n",a , depth);
			if(a == k)
			{
				printf("%d\n",depth);
				func(a);
				return 0;
			}
			if(visited[a]) continue;
			visited[a] = 1;

			if(a+1 <= 100000 && !visited[a+1])
			{
				if(precursor[a+1][1] > depth)
				{
					precursor[a+1][0] = a;
					precursor[a+1][1] = depth;
					q.push(a+1);
				}
			}
			if(a-1 >= 0 && !visited[a-1])
			{
				if(precursor[a-1][1] > depth)
				{
					precursor[a-1][0] = a;
					precursor[a-1][1] = depth;
					q.push(a-1);
				}
			}
			if( 2* a <= 100000 && !visited[2*a])
			{
				if(precursor[a*2][1] > depth)
				{
					precursor[a*2][0] = a;
					precursor[a*2][1] = depth;
					q.push(2*a);
				}
			}
			
		}
		depth++;
	}



	return 0;
}

