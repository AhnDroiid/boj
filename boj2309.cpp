#include <iostream>
using namespace std;
void Sort(int * arr, int size);

int main(void)
{
	int arr[9];
	int sum = 0;
	int sub = 0;
	for(int i=0; i<9; i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	int flag = 0;
	for(int i=0; i<8; i++)
	{
		for(int j=1; j<9; j++)
		{
			sub = (arr[i] + arr[j]);		
			if(sum-sub == 100)
			{
				arr[i] = 101;
				arr[j] = 101;
				flag = 1;
			    break;
			}
		}
		if(flag == 1)
				break;
		//printf("i : %d\n",i);
	}
	Sort(arr,9);
	for(int i=0; i< 7; i++)
		cout<< arr[i] << endl;
	return 0;
}
void Sort(int * arr, int size)
{
	int key;
	int j;
	for(int i=1; i<size; i++)
	{
		key = arr[i];
		for(j=i-1; j>=0 ; j--)
		{
			if(key < arr[j])
				arr[j+1] = arr[j];
			else
				break;
			
		}
		arr[j+1] = key;
		
	}
}

