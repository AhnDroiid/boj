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
int sol = 1;
vector<pair<int,int>> v;
bool comp(const pair<int,int> & a, const pair<int,int> & b)
{
	return a.second < b.second;
}
void solve(int idx)
{
	int finishVal = v[idx].second;
	int start = idx+1;
	while(start < n)
	{
		if(v[start].first >= finishVal)
		{
			sol++;
			finishVal = v[start].second;
		}
		start++;
	}
	return;
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	sort(&v[0],&v[n]);
	sort(&v[0],&v[n],comp);
	solve(0);
	printf("%d\n",sol);
	return 0;
}

