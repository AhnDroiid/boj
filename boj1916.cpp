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
class cmp
{
	public:
		bool operator()(const pair<int,int> &a, pair<int,int> &b)
		{
			return a.second > b.second;
		}
};
priority_queue <pair<int,int>,vector<pair<int,int>>, cmp> pq;
list<pair<int,int>> l[1001];
int city;
int bus;
int src,dst;
int dist[1001];
const int INF = 987654321;
void dijkstra(int s)
{
	dist[s] = 0;
	pq.push(make_pair(s,dist[s]));
	while(!pq.empty())
	{
		int c = pq.top().first;
		int w = pq.top().second;
		pq.pop();
		list<pair<int,int>>:: iterator iter;
		if(dist[c] < w) continue;
		else
		{
			for(iter = l[c].begin(); iter!= l[c].end(); iter++)
			{
				if(dist[(*iter).first] > (*iter).second + dist[c] )
				{
					dist[(*iter).first] = (*iter).second + dist[c] ;
					pq.push(make_pair((*iter).first,dist[(*iter).first])); 	
				}
			}	
		}
	}
}
int main(void)
{
	scanf("%d",&city);
	scanf("%d",&bus);
	for(int i =1; i<=city; i++)
		dist[i] = INF;
	for(int i = 0 ; i<bus; i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		l[a].push_back(make_pair(b,w));
	}
	scanf("%d %d",&src,&dst);
	dijkstra(src);
	printf("%d\n",dist[dst]);


	return 0;
}

