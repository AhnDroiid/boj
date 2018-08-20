#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
	deque<int> a;
	
	string b;
	
	cin >> b;
	
	for(int i =0; i<b.length(); i++)
	{
		if(a.empty()) a.push_back(b[i]);
		else
		{
			if(a.back() == '(' && b[i] == ')')
			{ 
				a.pop_back();
				a.push_back(2);
			}
			else if(a.back() == '[' && b[i] == ']')
			{
				a.pop_back();
			 	a.push_back(3);
			}
			else a.push_back(b[i]);
		}
	}
	// stacking ¿Ï·á
	for(int i=0; i<a.size(); i++)
		printf("%c ",a[i]);
	
	while(a.size() != 1)
	{
		int tmp = 0;
		for(int i=0; i<a.size(); i++)
		{
			if(a[i] == '(')
			{
				for(int j = i+1; j<=a.size(); j++)
				{
					if(a[j] != '(' && a[i] !=')' && a[i] != '[' && a[i] != ']')
						tmp += (a[j]);
					if(a[j] == ')')
					{
						if(tmp == 0)
							tmp = 2;
						else
							tmp*=2;
						a.pop_back();
						a.push_back(tmp);
						break;
					}
					if(a[j] == '[') break;
					if(a[j] == ']')
						{
							printf("?\n");
							printf("0\n");
							return 0;
						}
					a.pop_back();
				}
				a.push_back(tmp);
				tmp = 0;
			}
			else if(a[i] == '[')
			{
				for(int j = i+1; j<=a.size(); j++)
				{
					if(a[j] != '(' && a[i] !=')' && a[i] != '[' && a[i] != ']')
						tmp += a[j];
					if(a[j] == ']')
					{
						if(tmp == 0)
							tmp = 3;
						else
							tmp*=3;
						a.pop_back();
						a.push_back(tmp);
					}
					if(a[j] == '(') break;
					if(a[j] == ')')
						{
							printf("?\n");
							printf("0\n");
							return 0;
						}
					a.pop_back();
				}
				
				tmp = 0;
			}
		}
	}
	printf("%d\n",a[0]);
	return 0;
}

