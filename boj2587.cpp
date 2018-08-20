#include <iostream>
#include <cstdio>

int * arr;
void Sort(void)
{
	int key;
	int j;
	for(int i=1; i<5; i++)
	{
		key = arr[i];
		for(j=i-1; j>=0; j--)
		{
			if(arr[j] > key)
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = key;
	}
}

int main(void)
{
	arr= new int[5];
	int avg =0;
	int median;
	for(int i=0; i<5; i++)
	{
		scanf("%d",arr+i);
		avg+=arr[i];
	}
	avg /= 5;
	Sort();
	printf("%d\n%d\n",avg,arr[2]);
	return 0;
		
}
