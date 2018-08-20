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
int ccount = 0;
int mapp[26][26];
int visited[26][26];
stack<pair<int,int>> s;
int BFS(int a, int b)
{
	int x,y;
	int c = 1;
	//printf("%d %d\n",a,b);
	while(!s.empty())
	{
		
		x = s.top().first;
		y = s.top().second;
		//printf("x : %d , y : %d\n",x,y);
		s.pop();
		if(!visited[x][y])c++;
		mapp[x][y] = 0;
		visited[x][y] = 1;
		if((x+1) <= n && !visited[x+1][y] && mapp[x+1][y] == 1) s.push(make_pair(x+1,y));
		if((x-1) >= 1 && !visited[x-1][y] && mapp[x-1][y] == 1) s.push(make_pair(x-1,y));
		if((y+1) <= n && !visited[x][y+1] && mapp[x][y+1] == 1) s.push(make_pair(x,y+1));
		if((y-1) >= 1 && !visited[x][y-1] && mapp[x][y-1] == 1) s.push(make_pair(x,y-1));
	}
	return c;
}
int main(void)
{

	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		memset(visited[i],0,sizeof(int) * 26);
	string tmp;
	for(int i=1; i<=n; i++)
	{
		cin >> tmp;
		for(int j = 1; j<=n; j++)
			mapp[i][j] = tmp[j-1]-'0';
	}
	vector<int> result;
	//printf("?\n");
	for(int i=1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(mapp[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = 1;
				ccount++;
				s.push(make_pair(i,j));
				result.push_back(BFS(i,j));
			}
		}
	}
	sort(result.begin(),result.end(),less<int>());
	
	
	
	vector<int>::iterator iter;
	cout << ccount << endl;
	for(iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << endl;
	



	return 0;
}

