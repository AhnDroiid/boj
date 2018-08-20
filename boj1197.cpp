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
const int INF = 987654321;

class cmp
{
	public:
		bool operator()(const pair<int,int> & a, const pair<int,int> &b)
		{
			return a.second > b.second;
		}
};
vector<int> sol;
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
int n;
int vertex;
int visited[10001];
int minimum = 0;
list<pair<int,int>> l[10001];
void Prim(int s)
{
	pq.push(make_pair(s,0));
	while(!pq.empty())
	{
		int v = pq.top().first;
		if(!visited[v])
		{
			minimum+=pq.top().second;
			sol.push_back(v);
		}
		pq.pop();
		visited[v] = 1;
		list<pair<int,int>>:: iterator iter;
		for(iter = l[v].begin(); iter != l[v].end(); iter++)
		{
			if(!visited[(*iter).first])
			{
				pq.push(make_pair((*iter).first,(*iter).second));
			}
		}
	}
		
}
int main(void)
{
	scanf("%d %d",&vertex,&n);
	memset(visited,0,sizeof(int) * 10001);
	for(int i = 0; i<n; i++)
	{
		int a,b,w; 
		scanf("%d %d %d",&a,&b,&w);
		l[a].push_back(make_pair(b,w));
		l[b].push_back(make_pair(a,w));
	}
	Prim(1);
	vector<int>:: iterator iter;
	/*for(iter = sol.begin(); iter!= sol.end(); iter++)
		printf("%d ",*iter);
*/
	printf("%d\n",minimum);

	return 0;
}

