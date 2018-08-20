#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int N;
int weight[100001];
int sum = 0;
int minn = -1;
int main(void)
{
	scanf("%d",&N);
	for(int i = 1; i<=N; i++)
		scanf("%d",weight+i);
	sort(weight+1,weight+N+1,greater<int>());
	int cmp;
	int tmp;
	for(int i =1; i<=N; i++)
	{
		cmp = weight[i] * i;
		if(cmp >= minn)
		{
			minn = cmp;
			sum = cmp;
			tmp = cmp;
		}
		
			
	}
	printf("%d\n",sum);

	return 0;
}

