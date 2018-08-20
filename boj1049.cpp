#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int n,m;
vector<pair<int,int>> v;
bool cmp(const pair<int,int> & a, const pair<int,int> & b)
{
	if(a.second == 1 && b.second == 1)
		return a.first < b.first;
	if(a.second == 0 || b.second == 0)
	{
		if(a.second == 0 && b.second == 1)
			return a.first / (6+0.0) < (b.first + 0.0);
		if(a.second == 1 && b.second == 0)
			return (a.first+0.0) < (b.first / (6+0.0));
		if(a.second == 0 && b.second == 0)
			return (a.first / (6+0.0)) < (b.first / (6+0.0));
	}
}

bool cmp2(const pair<int,int> & a, const pair<int,int> & b)
{
	if(a.second == 0 && b.second == 0)
		return a.first < b.first;
	if(a.second == 1 || b.second == 1)
	{
		if(a.second == 1 && b.second == 0)
			return a.first *6 < b.first;
		if(a.second == 0 && b.second == 1)
			return a.first < b.first * 6;
		if(a.second == 1 && b.second == 1)
			return a.first  < b.first;
	}
}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,0));
		v.push_back(make_pair(b,1));
	}
	int money = 0;
	sort(v.begin(),v.end(),cmp2);

	int pack_num = n / 6;
	int npack_num = n  % 6;
	
	if(v[0].second == 1)
		money += (v[0].first * 6) * pack_num;
	else
		money += v[0].first * pack_num;
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i].second == 1)
			v[i].first *= npack_num;	
	}
	sort(v.begin(),v.end());
	money+= v[0].first;
	printf("%d\n",money);


	return 0;
}

