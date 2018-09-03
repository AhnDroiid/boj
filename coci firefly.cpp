#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n,h;
int val[500001];
int r[500001];
void print(void)
{
	for(int i = 1; i<=h; i++)
		printf("%d ",val[i]);
	printf("\n");
}
int main(void)
{
	scanf("%d %d",&n,&h);
	for(int k = 1; k<=n; k++)
	{
		int i;
		scanf("%d",&i);
		if(k%2 == 0)
		{
			val[h-i+1] += 1;
		}
		else
		{
			val[1] += 1;
			val[i+1]-= 1;
		}
	//	print();
	}
	for(int i = 1; i<=h; i++)
	{
		r[i] = r[i-1] + val[i];
	}
	sort(r+1,r+h+1);
	int minn = r[1];
	int ccount = 0;
	for(int i = 1; i<=h; i++)
	{
		if(r[i] == minn) ccount++;
		else break;
	}
	printf("%d %d\n",minn,ccount);
 	return 0;
}

