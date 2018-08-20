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
		
			int a,b;
			scanf("%d %d",&a,&b);
			
			cost[a][b] = 1;
			cost[b][a] = 1;
			mat[a][b] = cost[a][b];
			mat[b][a] = cost[a][b];
	}
	
	Floyd();
	int idx;
	int min = INF;
	for(int i = 1; i<=n; i++)
	{
		int sum = 0;
		for(int j = 1; j<=n; j++)
		{
			sum += mat[i][j];
		}
		//printf("sum  : %d\n",sum);
		if(min > sum)
		{
			min = sum;
		 	idx = i;
		}
	}
	printf("%d\n",idx);

	return 0;
}

