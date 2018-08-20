#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <string>
using namespace std;
int n;

int main(void)
{
	vector<pair<int,int>> v;
	
	int a,b;
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	for(int i = 0; i<v.size(); i++)
	{
		int k = 0;
		for(int j = 0; j<v.size(); j++)
		{
			
			if(i ==j) continue;
			if(v[j].first > v[i].first && v[j].second > v[i].second) k++;
		}
		printf("%d ",k+1);
	}
	printf("\n");


	return 0;
}

