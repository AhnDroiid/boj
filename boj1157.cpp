#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int arr['Z'+1];
int main(void)
{
	//cout << size << endl;
	string t;
	cin >> t;
	memset(arr,0,sizeof(arr));
	for(int i = 0; i<t.length(); i++)
	{
		if(t[i] >= 'a' && t[i] <='z')
			arr[t[i]+('A'-'a')]++;
		else
			arr[t[i]]++;
	}
	char max = 'A';
	for(int i = 'A'; i<='Z'; i++)
	{
		if(arr[i] > arr[max]) max = i;
	}
	int ccount = 0;
	for(int i = 'A'; i<='Z'; i++)
	{
		if(arr[i] == arr[max]) ccount++;
	}
	if(ccount <= 1) printf("%c\n",max);
	else printf("?\n");
	return 0;
}

