#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;

int n,k;
int arr[5000000];
void Merge(int first, int mid, int last)
{
	int left = first;
	int right = mid+1;
	int sorted[last-first+1];
	int idx = 0;
	while(left <=mid && right <= last)
	{
		if(arr[left] <= arr[right]) sorted[idx++] = arr[left++];
		else sorted[idx++] = arr[right++];
	}
	while(left <= mid)
		sorted[idx++] = arr[left++];
	while(right <= last)
		sorted[idx++] = arr[right++];
	for(int i=first, j = 0; i<=last && j < idx; i++,j++)
	{
		arr[i] = sorted[j];
	}
}

void MergeSort(int first, int last)
{
	int mid = (first+last)/2;
	if(first < last)
	{
		MergeSort(first,mid);
		MergeSort(mid+1,last);
		Merge(first,mid,last);
	}
}
int main(void)
{
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d",arr+i);
	MergeSort(0,n-1);
	printf("%d\n",arr[k-1]);


	return 0;
}

