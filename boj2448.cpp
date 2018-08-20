#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int half_space;
char arr[6500][6500];
void draw(int n,int startX, int startY,int half)
{
	if(n == 3)
	{
		arr[startX][startY] = '*';
		arr[startX+1][startY-1] = '*';
		arr[startX+1][startY] = ' ';
		arr[startX+1][startY+1] = '*';
		for(int i =0; i<5; i++)
		{
			arr[startX+2][startY-2+i] = '*';
		}
		return;
	}
	draw(n/2,startX,startY,half/2);
	draw(n/2,startX+n/2,startY-half/2-1,half/2);
	draw(n/2,startX+n/2,startY+half/2+1,half/2);
}
void Print(int n)
{
	for(int i = 1; i<=N; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			printf("%c",arr[i][j]);
		}
		if(i!=N)
			printf("\n");
	}
}
int main(void)
{
	scanf("%d",&N);
	int width = 5*(N/3) + (N/3 - 1);
	half_space = (width-1) / 2;
	
	
	draw(N,1,1+half_space,half_space);
	Print(width);


	return 0;
}

