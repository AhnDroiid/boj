#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
queue< pair<int,int> > q;
int n,m;
int val[1001][1001];
int visited[1001][1001];
void func(int x,int y)
{
	visited[x][y] = 1;
	val[x][y] = 1;
	q.push(make_pair(x,y));	
}
void bfs(int x, int y)
{
	
	visited[x][y] = 1;
	
		if(x+1 <=n && !visited[x+1][y] && val[x+1][y] == 0)
		{
			func(x+1,y);
		}
		if(x-1 >=1 && !visited[x-1][y] && val[x-1][y] == 0)
		{
			func(x-1,y);
		}
		if(y+1 <=m && !visited[x][y+1] && val[x][y+1] == 0)
		{
			func(x,y+1);
		}
		if(y-1 >=1 && !visited[x][y-1] && val[x][y-1] == 0)
		{
			func(x,y-1);
		}
		
	
}
int main(void)
{
	scanf("%d %d",&m,&n);
	for(int i =1 ; i<=n; i++)
	{
		for(int j = 1;  j<=m; j++)
		{
			scanf("%d",&val[i][j]);
			if(val[i][j] == 1)
				q.push(make_pair(i,j));
		}
	}
	int depth = 0;
	while(!q.empty())
	{
		int size = q.size();
		for(int i = 0 ; i<size; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			bfs(x,y);
		}
		depth++;
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
			if(val[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
	}
	printf("%d\n",depth-1);
 	return 0;
}

