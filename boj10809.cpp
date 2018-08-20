#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int alpha['z'+1];
int main(void)
{
	string t;
	cin >> t;
	memset(alpha,-1,sizeof(alpha));
	for(int i = 0; i<t.length(); i++)
	{
		if(alpha[t[i]] == -1)
			alpha[t[i]] = i;
	}
	for(int i = 'a' ; i<='z'; i++)
		printf("%d ",alpha[i]);
	printf("\n");


	return 0;
}

