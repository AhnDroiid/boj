#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int arr[1001][1001];
string a,b;
int main(void)
{
	cin >> a >> b;
	int flen = a.length();
	int slen = b.length();
	
	for(int i = 1; i<=flen; i++)
	{
		for(int j = 1; j<=slen; j++)
		{
			if(a[i-1] == b[j-1])
			{
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	
	
	printf("%d\n",arr[flen][slen]);



	return 0;
}

