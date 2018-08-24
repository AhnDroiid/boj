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
int maks[4];
int meen[4];
int a,b,c;
int main(void)
{
	scanf("%d",&n);
	
	for(int i = 0; i<n; i++)
	{
		int d,e,f;
		scanf("%d %d %d",&d,&e,&f);
		a = maks[1];
		b = maks[2];
		c = maks[3];
		maks[1] = max(a+d,b+d);
		maks[2] = max(a+e,b+e);
		maks[2] = max(maks[2],c+e);
		maks[3] = max(b+f,c+f);

		
		a = meen[1];
		b = meen[2];
		c = meen[3];
		meen[1] = min(a+d,b+d);
		meen[2] = min(a+e,b+e);
		meen[2] = min(meen[2],c+e);
		meen[3] = min(b+f,c+f);
	}
	sort(maks+1,maks+4,greater<int>());
	sort(meen+1,meen+4);
	printf("%d %d\n",maks[1],meen[1]);


	return 0;
}

