#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int pi[50][50];
int mat[50][50];
int cost[50][50];
int size;
int edge;
const int INF = 987654321;
void Floyd_wallshall(void)
{
	for(int k = 1; k<=size; k++)
	{
		for(int i = 1; i<=size; i++)
		{	
			for(int j =1; j<=size; j++)
			{
				printf("%d %d %d\n",i,j,k);
				mat[i][j] = min(mat[i][j] , mat[i][k] + cost[k][j]);
			}
		}
	}
}
int main(void)
{
	scanf("%d %d",&size,&edge);
	
	for(int i =1 ; i<=size; i++)
	{
		for(int j =1 ; j<=size; j++)
		{
			if(i==j) cost[i][j] = 0;
			else cost[i][j] = INF;
			mat[i][j] = cost[i][j];
		}
	}
	
	for(int i = 0; i<edge; i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		cost[a][b] = w;
		mat[a][b] = w;
	}
	Floyd_wallshall();
	for(int i = 1; i<=size; i++)
	{
		for(int j = 1; j<=size; j++)
		{
			
				printf("shortest path weight from %d to %d is %d\n",i,j,mat[i][j]);
			
		}
	}


	return 0;
}

