#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
vector<pair<int,int>> v;
vector<int> s;
int main(void)
{
	int tmp;
	for(int i = 0; i<8; i++)
	{
		scanf("%d",&tmp);
		v.push_back(make_pair(tmp,i+1));
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i = 3; i<8; i++)
		sum+=v[i].first;
	printf("%d\n",sum);
	for(int i = 3; i<8; i++) s.push_back(v[i].second);
	sort(s.begin(),s.end());
	for(int i = 0; i<5; i++) printf("%d ",s[i]);
	printf("\n");
	
	


	return 0;
}

