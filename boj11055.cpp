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
vector<pair<int,int>> v;
int val[1001];
bool cmp(pair<int,int> &a, pair<int,int> & b)
{
	return a.second < b.second;
}
int main(void)
{
	scanf("%d",&n);
	v.push_back(make_pair(0,0));
	for(int i = 1; i<=n; i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(make_pair(1,a));
		val[i] = a;
	}
	for(int i =1; i<=n; i++)
	{
		for(int j = 0; j < i ; j++)
		{
			if(val[i] > val[j])
			{
				v[i].first = max(v[i].first , v[j].first+1);
				v[i].second = max(v[i].second , v[j].second + val[i]);
			}
		}
	}
	/*for(int i =1; i<=n; i++)
		printf("%d %d\n",v[i].first,v[i].second);
		
	*/
	sort(&v[1],&v[n+1],cmp);
	printf("%d\n",v[n].second);


	return 0;
}

