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
int arr[3];
int main(void)
{

	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	sort(arr,arr+3);
	printf("%d\n",arr[1]);


	return 0;
}

