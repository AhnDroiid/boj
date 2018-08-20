#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
const int maxx = 100000+1;
string in;
int numArr[maxx];
bool flag = false;
int sum = 0;
int main(void)
{
	cin >> in;
	for(int i = 0; i< in.length(); i++)
	{
		if(in[i]-'0' == 0) flag = true;
		numArr[i+1] = in[i] - '0';
		sum += numArr[i+1];
	}
	sort(numArr+1,numArr+in.length()+1);
	if(!flag) printf("-1");
	else
	{
		if(sum % 3 != 0)
			printf("-1\n");
		else
		{
			for(int i = in.length(); i>=1; i--)
				printf("%d",numArr[i]);
			
		}
	}


	return 0;
}

