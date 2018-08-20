#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n;
int v[101][101];
int mat[101][101];
const int INF = 987654321;
void mult(void)
{
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			for(int k = 1; k<=n; k++)
			{
				if(mat[i][j] > mat[i][k] + mat[k][j])
					mat[i][j] = mat[i][k] + mat[k][j];
			}
		}	
	}
}
void FBF(void)
{
	int m = 1;
	while(m < n)
	{
		mult();
		m*=2;
	}
}
int main(void)
{
	scanf("%d",&n);
	
	

	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			scanf("%d",&v[i][j]);
			mat[i][j] = v[i][j];
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(v[i][j] == 0) v[i][j] = INF;
			mat[i][j] = v[i][j];
		}
	}
	FBF();
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(mat[i][j] < INF && mat[i][j] > 0)
				printf("%d ",1);
			else
				printf("%d ",0);
		}
		printf("\n");
	}

	return 0;
}

