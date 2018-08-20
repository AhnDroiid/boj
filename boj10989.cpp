#include <iostream>
#include <cstdio>
#include <cstring>
const int MAX = 100001;
int *arr;
int n;


int main(void)
{
	scanf("%d",&n);
	arr =new int[MAX];
	memset(arr,0,sizeof(int) * MAX);
	int tmp;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&tmp);
		arr[tmp]++;
	}
	for(int i=0; i<MAX;i++)
	{
		while(arr[i] != 0)
		{
			printf("%d\n",i);
			arr[i]--;
		}
	}
	return 0;
}



