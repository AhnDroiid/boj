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
int main(void)
{
	scanf("%d",&n);
	string tmp;
	deque<int> s;

	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		if(tmp == "push")
		{
			int t;
			scanf("%d",&t);
			s.push_back(t);
		}
		else
		{
			if(tmp == "front")
			{
				if(s.empty()) printf("%d\n",-1);
				else
					printf("%d\n",s.front());
			}
			else if(tmp == "back")
			{
				if(s.empty()) printf("%d\n",-1);
				else
					printf("%d\n",s.back());
			}
			else if(tmp == "pop")
			{
				if(s.empty()) printf("%d\n",-1);
				else
				{
					printf("%d\n",s.front());
					s.pop_front();
				}
			}
			else if(tmp == "size")
			{
				printf("%d\n",s.size());
			}
			else if(tmp == "empty")
			{
				if(s.empty()) printf("%d\n",1);
				else printf("%d\n",0);
			}
		}
	}



	return 0;
}

