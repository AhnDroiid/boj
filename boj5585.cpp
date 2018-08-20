#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
int in;
int sol = 0;
int arr[6] = {500,100,50,10,5,1};
void solve(int money, int i)
{
	if(money == 0) return;
	sol += money/arr[i];
	solve(money%arr[i],i+1);
	
}
int main(void)
{
	scanf("%d",&in);
	in = 1000-in;
	solve(in,0);
	printf("%d\n",sol);


	return 0;
}

