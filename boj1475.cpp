#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
string n;
int summ;
int v[9];
int solve(void)
{
	for(int i = 0 ; i<n.length(); i++)
	{
		if(n[i] != '9')
		{
			if(v[n[i]-'0'] == 0)
			{
				summ++;
				for(int j = 1; j<=8; j++)
					v[j]++;
				v[6]++;
				v[n[i]-'0']--;
			}
			else
			{
				v[n[i]-'0']--;
			}
		}
		else
		{
			if(v[6] == 0)
			{
				summ++;
				for(int j = 1; j<=8; j++)
					v[j]++;
				v[6]++;
				v[6]--;
			}
			else
			{
				v[6]--;
			}
		}
	}
	return summ;
}
int main(void)
{

	cin >> n;
	printf("%d\n",solve());


	return 0;
}

