#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
queue< pair<int,int> > q;
int visited[101][101];
int val[101][101];
int n,m;
void solve(void)
{
	q.push(make_pair(0,0));
	visited[0][0] = 1;
	int depth = 1;
	int size;
	while(!q.empty())
	{
		size = q.size();
	//	printf("%d\n",size);
		for(int i = 0 ; i < size; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visited[x][y] = 1;
		//	printf("x : %d , y: %d\n",x,y);
			if(x == n-1 && y == m-1)
			{
				printf("%d\n",depth);
				return;
			}
			else
			{
				if(x+1 <n && !visited[x+1][y] && val[x+1][y] == 1)
				{
					q.push(make_pair(x+1,y));
					visited[x+1][y] = 1;
				}
				if(y+1 <m && !visited[x][y+1] && val[x][y+1] == 1)
				{
					q.push(make_pair(x,y+1));
					visited[x][y+1] = 1;
				}
				if(x-1 >=0 && !visited[x-1][y] && val[x-1][y] == 1)
				{
					q.push(make_pair(x-1,y));
					visited[x-1][y] = 1;
				}
				if(y-1 >=0 && !visited[x][y-1] && val[x][y-1] == 1)
				{
					q.push(make_pair(x,y-1));
					visited[x][y-1] = 1;
				}
			}
		}
		depth++;
	}
	return;
}
int main(void)
{
	scanf("%d %d",&n,&m);
	string tmp;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		for(int j = 0; j<m; j++)
			val[i][j] = tmp[j] -'0';
	}
	solve();
 	return 0;
}

