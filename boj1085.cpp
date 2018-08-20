#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#define MIN(a,b) (a<b? a:b)
using namespace std;
int x,y,w,h;
int main(void)
{
	scanf("%d %d %d %d",&x,&y,&w,&h);
	int t1,t2,t3,t4;
	t1 = x;
	t2 = abs(x-w);
	t3 = y;
	t4 = abs(y-h);
	printf("%d\n",MIN(MIN(MIN(t1,t2),t3),t4));

	return 0;
}

