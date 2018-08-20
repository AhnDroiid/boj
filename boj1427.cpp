#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void Merge(int first, int mid, int last);
void MergeSort(int first, int last);
//long long count = 0;
int n;
int * arr;
int main(void)
{
	char str[10];
	scanf("%s",str);
	int len = strlen(str);
	arr = (int*)malloc(sizeof(int) * len);
	for(int i=0; i<len;i++)
	{
		arr[i] = str[i] - '0';
	}
	MergeSort(0,len-1);
	for(int i=len-1; i>=0; i--)
	{
		printf("%d",arr[i]);
	}
	return 0;
}

void Merge(int first, int mid, int last)
{
	int start = first;
	int second = mid+1;
	int idx = 0;
	int arr2[last-first];
	while(start <= mid && second <= last)
	{
		if(arr[start] < arr[second])
			arr2[idx++] = arr[start++];
		else
		{
			//count += (mid-start+1);
			arr2[idx++] = arr[second++];
		}
	}
	while(start <= mid)
		arr2[idx++] = arr[start++];
	while(second <=last)
		arr2[idx++] = arr[second++];
	
	for(int i=first,j=0; i<=last; i++,j++)
		arr[i] = arr2[j];
	
	
}

void MergeSort(int first, int last)
{
	int mid = (first + last) / 2 ;
	
	if(first < last)
	{
		MergeSort(first,mid);
		MergeSort(mid+1,last);
		Merge(first,mid,last);
	}
}

