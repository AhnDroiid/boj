#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

bool com(string n1, string n2)
{
	if(n1.length() < n2.length())
		return true;
	else if(n1.length() == n2.length())
	{
		if(n1<n2) return true;
		if(n1 > n2)return false;
	}
	else return false;
	
}

int main(void)
{
	int n;
	scanf("%d",&n);
	string arr[n];
	string tmp;
	int flag;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n,com);
	for(int i=0; i<n; i++)
	{
		if(arr[i] != arr[i+1])
			cout <<arr[i] << endl;
	}

	return 0;
}

