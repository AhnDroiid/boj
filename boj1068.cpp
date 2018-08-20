#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int v[51];
int parent[51];
list<int> child[51];
deque<int> q;
int n;
int r;


int main(void)
{
	scanf("%d",&n);
	for(int i = 0; i< n ; i++)
	{
		int a;
		scanf("%d",&a);
		if(a != -1)
		{ 
			v[a]++;
			parent[i] = a; 
			child[a].push_back(i);
		}
	}

	scanf("%d",&r);
	v[r] = -1;
	v[parent[r]]--;
	
	
	q.push_back(r);
	
	while(!q.empty())
	{
		int a = q.front();
		q.pop_front();
		list<int>:: iterator iter;
		for(iter = child[a].begin(); iter!=child[a].end(); iter++)
		{
			if(v[(*iter)] != -1)
			{
				q.push_back((*iter));
				v[(*iter)] = -1;			
			}
		}
	}
	
	
	int sol = 0;
	for(int i = 0; i<n; i++)
	{
		if(v[i] == 0)
			sol++;
		//printf("%d ",v[i]);
	}
	printf("%d\n",sol);
	

	return 0;
}

