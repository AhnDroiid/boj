#include <iostream>
#include <cstdio>
#define MAX_SIZE 500000
#include <cmath>

int num1;
int num2;
int searchnum;
int ret = 0;
int * arr;
int * positive = new int[10000000+50];
int * posvisited = new int[10000000+50];
int * negative = new int[10000000+50];
int * negvisited = new int[10000000+50];
void Bisection(int first, int last,int n);
void Merge(int start, int last);
void MergeSort(int first, int last);
void PrintArray(void);
int main(void)
{
	scanf("%d",&num1);
	arr = new int[num1];
	
	for(int i=0; i<num1; i++)
	{
		scanf("%d",&arr[i]);
	}
	//printf("d\n");
	MergeSort(0,num1-1);
	//PrintArray();
	scanf("%d",&num2);
	
	for(int i=0; i<num2; i++)
	{
		scanf("%d",&searchnum);
		if(searchnum > 0)
		{
			if(posvisited[searchnum])
				printf("%d ",positive[searchnum]);
			else
			{
				Bisection(0,num1-1,searchnum);
				printf("%d ",ret);
				posvisited[searchnum] = 1;
				positive[searchnum] = ret;
			}	
		}
		else
		{
			int ab = abs(searchnum);
			if(negvisited[ab])
				printf("%d ",negative[ab]);
			else
			{
				Bisection(0,num1-1,searchnum);
				printf("%d ",ret);
				negvisited[ab] = 1;
				negative[ab] = ret;
			}
		}
		ret = 0;
	}
	
}
void PrintArray(void)
{
	for(int i=0; i<num1; i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void Merge(int start, int last)
{
	int first = start;
	int mid = (first+last)/2;
	int second = mid+1;
	int sort[MAX_SIZE];
	int ind = start;
	
	while(first <=mid && second <= last)
	{
		if(arr[first] <= arr[second])
			sort[ind++] = arr[first++];
		else
			sort[ind++] = arr[second++];
		
	}
	if(first > mid)
	{
		for(int j= second; j<=last; j++)
			sort[ind++] = arr[j];
	}
	else
	{
		for(int j= first; j<=mid; j++)
				sort[ind++] = arr[j];
	}
	for(int i=start; i< last+1; i++)
		arr[i] = sort[i];
}
void MergeSort(int first, int last)
{
	int mid = (first + last) / 2;
	if(first < last)
	{
		MergeSort(first,mid);
		MergeSort(mid+1,last);
		Merge(first,last);
	}
}
void Bisection(int first, int last,int n)
{
	int mid = (first+last)/2;
	int temp1 = mid-1;
	int temp2 = mid+1;
	
	if(first > last) return; 
	if(arr[mid] == n)
	{	
		ret++;
		while(temp1>=first && arr[temp1--] == arr[mid])
			ret++;
		while(temp2 <= last && arr[temp2++] == arr[mid])
			ret++;
		return;
	}
	else if(arr[mid] > n) Bisection(first,mid-1,n);
	else Bisection(mid+1,last,n);
}

