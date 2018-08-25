#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int v[10];
int main(void)
{

	int sum = 0;
	for(int i = 0; i<9; i++)
	{
		scanf("%d",&v[i+1]);
		sum += v[i+1];
	}
	int i,j,flag;
	flag = false;
	for(i = 1; i<9; i++)
	{
		for(j = 2; j<=9; j++)
		{
			if((sum - (v[i] + v[j])) == 100)
			{ 
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	for(int a = 1; a <= 9 ; a++)
	{
		if(a == i || a == j)
			continue;
		printf("%d\n",v[a]);
	}
	return 0;
}

