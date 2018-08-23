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
int main(void)
{
	list<int> v;
	list<int>::iterator iter;
	vector<int> c;
	scanf("%d %d",&n,&m);
	for(int i = 0; i<n; i++)
		v.push_back(i+1);
	iter = v.begin();
	for(int i =1; i<m; i++)
		iter++;
	while(!v.empty())
	{
		c.push_back(*iter);
		iter = v.erase(iter);
		if(iter == v.end())
			iter = v.begin();
		for(int i =1; i<m; i++)
		{
			iter++;
			if(iter == v.end())
				iter = v.begin();
		}
	}
	printf("<");
	for(int i = 0; i<c.size(); i++)
	{
		if(i != c.size()-1)
			printf("%d, ",c[i]);
		else
			printf("%d>\n",c[i]);
	}


	return 0;
}

