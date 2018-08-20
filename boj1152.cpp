#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(void)
{
	char* c = new char[1230123];
	int cnt = 0;

	fgets(c,1230123,stdin);
	int flag = 0;
	for(int i=0; i<strlen(c); i++)
	{
		if( ('a' <= c[i] && 'z' >= c[i]) || ('A' <=c[i] && 'Z' >= c[i]))
		{
			flag = 1;
		}
		else
		{
			if(flag) cnt++;
			flag = 0;
		}
	}
	printf("%d\n",cnt);


	return 0;
}

