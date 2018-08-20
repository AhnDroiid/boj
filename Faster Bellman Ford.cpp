#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int cost[50][50];
int mat[50][50];
int size;
int edge;
const int INF = 987654321;
void Calculate_Matrix(void)
{
	for(int i = 1; i<=size; i++)
	{
		for(int j = 1; j<=size; j++)
		{
			for(int k = 1; k<=size; k++)
			{	
				if(cost[k][j] != INF)
					mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
			}
		}
	}
}
void Faster_Bellman(void)
{
	int m = 1;
	while(m < size)
	{
		Calculate_Matrix();
		m *= 2;
	}
} 
int main(void)
{

	scanf("%d %d",&size,&edge);
	for(int i = 1; i<=size; i++)
	{
		for(int j = 1; j<=size; j++)
		{
			if(i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	}
	for(int i = 0; i< edge; i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		cost[a][b] = w;
	}
	for(int i = 1; i<=size; i++)
	{
		for(int j = 1; j<=size; j++)
		{
			mat[i][j] = cost[i][j];
		}
	}
	Faster_Bellman();    v    
	for(int i = 1; i<=size; i++)
	{
		for(int j = 1; j<=size; j++)
		{
			
				printf("shortest path weight from %d to %d is %d\n",i,j,mat[i][j]);
			
		}
	}
	return 0;
}

