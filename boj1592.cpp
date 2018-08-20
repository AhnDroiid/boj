#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,m,l;
int rm,lm;
int a[1001];
int main(void)
{
	scanf("%d %d %d",&n,&m,&l);
	rm = n - l;
	lm = n + l;
	int ccount = 0;
	int i  = -1;
	int idx = 1;
	while(1)
	{
		a[idx]++;
		if(a[idx] == m) break;
		ccount++;
		if(a[idx] % 2 == 1) idx = (idx + rm) % n;
		else idx = (idx + lm) % n;
	}
	printf("%d\n",ccount);

	return 0;
}

