#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int v[1001];
int s[1001];
int n;
int main(void)
{
	scanf("%d",&n);
	memset(s,0,sizeof(s));
	s[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&v[i]);
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j])
				s[i] = max(s[i], s[j] + 1);
		}
	}

	sort(&s[0],&s[n+1]);
	printf("%d\n",s[n]);

	return 0;
}

