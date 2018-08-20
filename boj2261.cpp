#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;

typedef struct __point
{
	int x;
	int y;
}Point;

Point * arr;
bool comX(const Point &p, const Point &q){return p.x < q.x;}
bool comY(const Point &p, const Point &q){return p.y < q.y;}

int f(int num)
{
	
}
int main(void)
{
	scanf("%d",&n);
	arr = (Point*)malloc(sizeof(Point) * n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&(arr[i].x),&(arr[i].y));
	}
	sort(arr,arr+n,comX);
	
}

