#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int x1,y1,r1,x2,y2,r2;
int tc;
int dist(int fX,int fY,int tX,int tY)
{
	return (fX-tX) * (fX-tX) + (fY-tY) * (fY-tY);
}
int main(void)
{
	scanf("%d",&tc);
	
	for(int i = 0; i<tc; i++)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		int distance  = dist(x1,y1,x2,y2);
		/*printf("distance : %d\n",distance);
		printf("r1-r2 square : %d\n",(r1-r2) * (r1-r2));
		printf("r1+r2 square : %d\n", (r1+r2) * (r1+r2));
		*/
		if(x1 == x2 && y1 == y2 && r1 == r2)
		{
			printf("%d\n",-1);
		}
		else if(distance > ((r1+r2)*(r1+r2)))
		{
			printf("%d\n",0);	
		}
		else if(distance == ((r1+r2)* (r1+r2)))
		{
			printf("%d\n",1);
		}
		else if(distance < ((r1+r2)* (r1+r2)) && distance > ((r1-r2)* (r1-r2)))
		{
			printf("%d\n",2);
		}
		else if(distance == ((r1-r2)* (r1-r2)))
		{
			printf("%d\n",1);
		}
		else if(distance < ((r1-r2)* (r1-r2)))
		{
			printf("%d\n",0);
		}
	}

	return 0;
}

