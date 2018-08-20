#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,m;
int cost[101][101];
int mat[101][101];
const int INF = 987654321;
void Floyd(void)
{
	for(int k = 1; k<=n; k++)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				if(i == j) continue;
				if(mat[i][j] > mat[i][k] + mat[k][j])
				{
					//printf("k : %d m i: %d, j: %d\n",k,i,j);
					mat[i][j] = mat[i][k] + mat[k][j];
				}
			}
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(i== j) cost[i][j] = 0;
			else  cost[i][j] = INF;
			mat[i][j] = cost[i][j];
		}
	}
	for(int i = 1; i<=m; i++)
	{
		
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			if(cost[a][b] == INF || cost[a][b] > w)
				cost[a][b] = w;
			mat[a][b] = cost[a][b];
	}
	/*for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(cost[i][j] == INF) printf("INF ");
			else printf("%d ",cost[i][j]);
		}
		printf("\n");
	}*/
	Floyd();
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(mat[i][j] == INF) printf("0 ");
			else printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}

