#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int visited[1000001];
queue<int> q;
int n,k;
void solve(int num)
{
	q.push(num);
	int depth = 0;
	if(num == k)
	{
		printf("0\n");
		return;
	}
	while(!q.empty())
	{
		int a;
		int size = q.size();
		for(int i = 0 ; i <size; i++)
		{
			a = q.front();
			q.pop();
			visited[a] = 1;
			if(a == k)
			{
				printf("%d\n",depth);
				return;
			}
			else
			{
				if(a + 1 <= 100000 && !visited[a+1])
					q.push(a+1);
				if(a-1 >= 0 && !visited[a-1])
					q.push(a-1);
				if(a * 2 <= 100000 && !visited[2*a])
					q.push(2*a);
			}
		}
		depth++;
	}
	return;
}
using namespace std;

int main(void)
{
	scanf("%d %d",&n,&k);
	solve(n);
 	return 0;
}

