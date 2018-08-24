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
int val[1001];
int nval[1001];
list<pair<int,int>> v[1001];
int n,m,x;
priority_queue<pair<int,int>> pq;
const int INF = 987654321;
void Dijkstra(int src)
{
	while(!pq.empty())
		pq.pop();
	pq.push(make_pair(src,0));
	list<pair<int,int>>:: iterator iter;
	int c,w;
	while(!pq.empty())
	{
		c = pq.top().first;
		w = pq.top().second;
		pq.pop();
		if(val[c] < w) continue;
		else
		{
			for(iter = v[c].begin(); iter != v[c].end(); iter++)
			{
				if(val[(*iter).first] > w + (*iter).second)
				{
					val[(*iter).first] = w + (*iter).second;
					pq.push(make_pair((*iter).first,val[(*iter).first]));
				}
			}
		}
	}
}
int sDijkstra(int src)
{
	nval[src] = 0;
	for(int i = 1; i<=n; i++)
		if(i != src) nval[i] = INF;
	while(!pq.empty())
		pq.pop();
	pq.push(make_pair(src,0));
	list<pair<int,int>>:: iterator iter;
	int c,w;
	while(!pq.empty())
	{
		c = pq.top().first;
		w = pq.top().second;
		pq.pop();
		if(nval[c] < w) continue;
		else
		{
			for(iter = v[c].begin(); iter != v[c].end(); iter++)
			{
				if(nval[(*iter).first] > w + (*iter).second)
				{
					nval[(*iter).first] = w + (*iter).second;
					pq.push(make_pair((*iter).first,nval[(*iter).first]));
				}
			}
		}
	}
	return nval[x];
}
int main(void)
{
	scanf("%d %d %d",&n,&m,&x);
	val[x] = 0;
	for(int i = 1; i<=n; i++)
	{
		if(i!=x)
			val[i] = INF;
	}
	
	for(int i = 0; i<m; i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		v[a].push_back(make_pair(b,w));
	}
	Dijkstra(x);
	for(int i = 1; i<=n; i++)
	{
		if(i!=x)
		{
			val[i] += sDijkstra(i);
		}
	}
	sort(val+1,val+n+1,greater<int>());
	printf("%d\n",val[1]);


	return 0;
}

