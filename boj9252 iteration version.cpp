#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#define MAX(a,b) a>b? a:b
using namespace std;
string s1,s2;
deque<char> v;
int n,m;
int dp[1001][1001];
string sol;
int main(void)
{

	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
				dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[n][m] << endl;
	int i = n;
	int j = m;
	while(dp[i][j] != 0)
	{
		if (dp[i][j] == dp[i - 1][j]  ) {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else {
        	
            sol = s1.at(i-1) + sol;
            i--;
            j--;
        }
	}
	cout << sol << endl;
	



	return 0;
}

