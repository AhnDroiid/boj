#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <queue>
using namespace std;
int n,m;
int dist;
int visited[1001];
list<pair<int,int>> l[1001];
int sol;
class cmp
{
	public:
		bool operator()(const pair<int,int> & a, const pair<int,int> & b)
		{
			return a.second > b.second;
		}
};
priority_queue <pair<int,int>,vector<pair<int,int>>, cmp> pq;
void Prim(void)
{
	pq.push(make_pair(1,0));
	while(!pq.empty())
	{
		int c = pq.top().first;
		int w = pq.top().second;
		pq.pop();
		if(visited[c]) continue;
		visited[c] = 1;
		sol+=w;
		list<pair<int,int>>:: iterator iter;
		for(iter = l[c].begin(); iter!= l[c].end(); iter++)
		{
			if(!visited[(*iter).first])
				pq.push(make_pair((*iter).first,(*iter).second));
		}
		
	}
}
int main(void)
{

	scanf("%d %d",&n,&m);
	for(int i = 0; i<m; i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		l[a].push_back(make_pair(b,w));
		l[b].push_back(make_pair(a,w));
	}
	Prim();
	printf("%d\n",sol);


	return 0;
}

