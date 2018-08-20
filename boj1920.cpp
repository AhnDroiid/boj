#include <iostream>
#include <cstdio>
int num1;
int num2;
int * arr;


bool check(int first, int last, int n);
void MergeSort(int first, int last);
int main(void)
{
	int searchnum;
	scanf("%d",&num1);
	arr = new int[num1];
	for(int i=0; i<num1; i++)
		scanf("%d",&arr[i]);
	MergeSort(0,num1);
	scanf("%d",&num2);
	
	for(int i=0; i< num2; i++)
	{
		scanf("%d",&searchnum);
		if(check(0,num1,searchnum))
			printf("1 ");
		else
			printf("0 ");
	}
	
}
void Merge(int start, int last)
{
	int first = start;
	int mid = (first+last)/2;
	int second = mid+1;
	int sort[num1];
	int ind = start;
	
	while(first <=mid && second <= last)
	{
		if(arr[first] < arr[second])
			sort[ind++] = arr[first++];
		else
			sort[ind++] = arr[second++];
		
	}
	if(first== mid+1)
	{
		while(second <= last)
			sort[ind++] = arr[second++];
	}
	else
	{
		while(first <= mid)
			sort[ind++] = arr[first++];
	}
	for(int i=start; i< last+1; i++)
		arr[i] = sort[i];
}
void MergeSort(int first, int last)
{
	int mid = (first + last) / 2;
	if(first == last) return;
	
	MergeSort(first,mid);
	MergeSort(mid+1,last);
	Merge(first,last);
}
bool check(int first, int last, int n)
{
	int mid = (first + last) / 2;
	if(arr[mid] == n) return true;
	if(first > last) return false;
	else
	{
		if(arr[mid] > n) check(first,mid-1,n);
		else check(mid+1, last, n);
	}
	
}
