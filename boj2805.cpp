#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2000000000

void Merge(long long first, long long mid, long long last);
void MergeSort(long long first, long long last);
void check(long long idx);
long long treenum;
long long need;
long long sol;
long long * arr;
void Print(void)
{
	for(int i=0; i<treenum; i++)
		printf("%lld ",arr[i]);
	printf("\n");
	return;
}
int main(void)
{
	scanf("%lld %lld",&treenum,&need);
	arr = (long long*)malloc(sizeof(long long) * treenum);
	for(int i=0; i<treenum; i++)
	{
		scanf("%lld",&arr[i]);
	}
	MergeSort(0,treenum-1);
	//Print();
	check(treenum-1);
	printf("%lld",sol);
	return 0;
	
}
void check(long long idx)
{
	long long i;
	long long sum =0;
	long long result;
	for(i=0;i<=idx;i++)
	{
		sum += arr[i];
		result = (sum-need)/ (i+1);
		if(i == idx)
		{
			sol = result;
			return;
		}
		if(result < arr[i+1])
			continue;
		else
		{
			sol = result;
			break;
		}
	}
	
}

void Merge(long long first, long long mid, long long last)
{
	long long i = first;
	long long j = mid+1;
	long long idx = 0;
	long long sorted[last-first];
	while(i<=mid && j<= last)
	{
		if(arr[i] > arr[j])
			sorted[idx++] = arr[i++];
		else
			sorted[idx++] = arr[j++];
	}
	while(i<=mid)
		sorted[idx++] = arr[i++];
	while(j<=last)
		sorted[idx++] = arr[j++];
	for(long long m =first,n =0; m <=last; m++,n++)
		arr[m] = sorted[n];
}
void MergeSort(long long first, long long last)
{
	if(first < last)
	{
		long long mid = (first+last) / 2;
		MergeSort(first,mid);
		MergeSort(mid+1,last);
		Merge(first,mid,last);
	}
}

