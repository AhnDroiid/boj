#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{

	stack<char> a;
	string c;
	int n;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		cin >> c;
		for(int j = 0; j<c.size(); j++)
		{
			if(a.empty())
				a.push(c[j]);
			else
			{
				if(c[j] == ')' && a.top() == '(')
				{
					a.pop();
				}
				else
					a.push(c[j]);
			}
		}
	
		if(!a.empty())
			printf("NO\n");
		else
		{
			printf("YES\n");
		}
		while(!a.empty())
			a.pop();
	}
		

	return 0;
}

