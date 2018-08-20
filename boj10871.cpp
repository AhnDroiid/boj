#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int N,X;
int main(void)
{
	scanf("%d %d",&N,&X);
	int tmp;
	for(int i=0; i<N; i++)
	{
		scanf("%d",&tmp);
		if(tmp < X) printf("%d ",tmp);
	}
	printf("\n");



	return 0;
}

