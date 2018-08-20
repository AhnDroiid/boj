#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int arr[51][51];
int a,b;
stack<pair<int,int>> s;
bool chk(int r, int s)
{
	if(r <= 0 || s <= 0 || r > b || s > a) return false;
	else return true;
}
void DFS(int x, int y)
{
	s.push(make_pair(x,y));
	
	while(!s.empty())
	{
		int row = s.top().first;
		int col = s.top().second;
		s.pop();
		arr[row][col] = 0;
		if(chk(row-1,col) && arr[row-1][col] == 1) s.push(make_pair(row-1,col)); 
		if(chk(row+1,col) && arr[row+1][col] == 1) s.push(make_pair(row+1,col)); 
		if(chk(row,col-1) && arr[row][col-1] == 1) s.push(make_pair(row,col-1)); 
		if(chk(row,col+1) && arr[row][col+1] == 1) s.push(make_pair(row,col+1)); 
		if(chk(row-1,col-1) && arr[row-1][col-1] == 1) s.push(make_pair(row-1,col-1)); 
		if(chk(row-1,col+1) && arr[row-1][col+1] == 1) s.push(make_pair(row-1,col+1)); 
		if(chk(row+1,col-1) && arr[row+1][col-1] == 1) s.push(make_pair(row+1,col-1)); 
		if(chk(row+1,col+1) && arr[row+1][col+1] == 1) s.push(make_pair(row+1,col+1)); 
		
	}	
}
int solve(int row, int col)
{
	int ccount = 0;
	for(int i = 1; i<=row; i++)
	{
		for(int j = 1; j<=col; j++)
		{
			if(arr[i][j] == 1)
			{ 
				DFS(i,j);
				ccount++;
			}
		}
	}
	return ccount;
}
int main(void)
{
	
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(a == 0 && b == 0) break;
		else
		{
			while(!s.empty()) s.pop();
			for(int row = 1; row<=b; row++)
			{
				for(int col = 1; col<=a; col++)
				{
					scanf("%d",&arr[row][col]);
				}
			}
			printf("%d\n",solve(b,a));
		}
	}

	return 0;
}

