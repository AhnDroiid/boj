#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#define FOR(a,b) for(a = 1; a<=b; a++)
using namespace std;
int n;
int board[21][21];
int tmpboard[21][21];
int dir[5][2] = {{-5,-5},{1,0},{-1,0},{0,1},{0,-1}};
int max = -12345;
void copy(void)
{
	int i,j;
	FOR(i,n) FOR(j,n) tmpboard[i][j] = board[i][j];
}
void move(int m)
{
	int i,j;
	FOR(i,n)
	{
		FOR(j,n)
		{
			
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
			scanf("%d",&board[i][j]);
	}
	int a,b,c,d,e;
	FOR(a,4)
	{
		FOR(b,4)
		{
			FOR(c,4)
			{
				FOR(d,4)
				{
					FOR(e,4)
					{
						copy();
						
					}
				}
			}
		}	
	}


	return 0;
}

