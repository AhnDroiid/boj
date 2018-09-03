#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
string t[101];
int main(void)
{
	scanf("%d",&n);
	int one,two;
	for(int i = 1; i<=n; i++)
	{
		string tmp;
		cin >> tmp;
		if(tmp == "KBS1") one = i;
		if(tmp == "KBS2") two = i;
		t[i] = tmp;
	}
	int idx = 1;
	string sol = "";
	if(two < one)
	{
		for(int i = 1; i<two; i++)
			sol = sol + "1";
		for(int i = 1; i<two; i++)
			sol = sol + "4";
		for(int i = 1; i<one; i++)
			sol = sol + "1";
		for(int i = 1; i<one; i++)
			sol = sol + "4";
		 
	}
	else
	{
		for(int i = 1; i<one; i++)
			sol = sol + "1";
		for(int i = 1; i<one; i++)
			sol = sol + "4";
		for(int i = 1; i<two; i++)
			sol = sol + "1";
		for(int i = 2; i<two; i++)
			sol = sol + "4";
	}
	cout << sol << endl;
 	return 0;
}

