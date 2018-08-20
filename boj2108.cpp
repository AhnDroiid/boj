#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;
int ccount[8001];

int arr[500000];
int main(void)
{
	int n;
	int sum = 0;
	scanf("%d",&n);
	memset(ccount,0,sizeof(int) * 8001);
	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
		ccount[arr[i]+4000]++;
	
		sum+=arr[i];
	}
	sort(arr,arr+n,less<int>());
	if(sum > 0)
		printf("%d\n%d\n",(int)((sum)/((double)n) + 0.5),arr[n/2]);
	else
		printf("%d\n%d\n",(int)((sum)/((double)n) - 0.5),arr[n/2]);
	int max = 0;
	for(int i =0; i<8001; i++)
	{
		if(ccount[max] <= ccount[i])
			max = i;
	}
	int c= 0;
	for(int i = 0; i<=max; i++)
	{
		if(ccount[i] == ccount[max]) c++;
		//printf("i : %d , c: %d\n",i,c);
		if(i == max) 
		{
			printf("%d\n",max-4000);
			break;
		}
		if(c == 2)
		{
			printf("%d\n",i-4000);
			break;
		}
	}
	printf("%d\n",arr[n-1]-arr[0]);
	return 0;
}

