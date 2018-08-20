#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
typedef unsigned long long ull;
vector<ull> s;
void init(void)
{
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
}
void func(void)
{
	for(int i = 7; i<=7+1000; i++)
	{
		s.push_back(s[i]+s[i-4]);
	}
}
int tc;
int n;
int main(void)
{
	scanf("%d",&tc);
	init();
	func();
	for(int i = 0; i<tc; i++)
	{
		scanf("%d",&n);
		printf("%llu\n",s[n-1]);
	}



	return 0;
}

