#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;



int maks = 0;
int n;
int tc;
int **arr;
int findMax(void);

int main(void)
{
	scanf("%d",&tc);
	arr = (int**)malloc(sizeof(int*) * 2);
	for(int i=0; i< tc; i++)
	{
		scanf("%d",&n);
		for(int j =0; j<2; j++)
		{
			arr[j] = (int*)malloc(sizeof(int) * n);
			for(int b=0; b<n; b++)
				scanf("%d",&(arr[j][b]));
		}
		
		while(1)
			{
				if(!findMax())
					break;
			}
			printf("%d\n",maks);
			maks = 0;
		
	}
}
int findMax(void)
{
	int flag = 0;
	int fmax = 0;
	int lmax= 0;
	for(int a = 1; a < n; a++)
	{
		if(arr[0][a] == 0) continue;
		else
			flag = 1;
		if(arr[0][fmax] < arr[0][a])
		{
			fmax = a;
		}
	}
	
	for(int a = 1; a<n; a++)
	{
		if(arr[1][a] == 0) continue;
		else
			flag = 1;
		if(arr[1][lmax] < arr[1][a])
		{
			lmax = a;
		}
	}
	if(arr[0][fmax] > arr[1][lmax])
	{
		maks+=arr[0][fmax];
		arr[0][fmax] = 0;
		arr[0][fmax+1] = 0;
		arr[0][fmax-1] = 0;
		arr[1][fmax] = 0;
	}
	else
	{
		maks+=arr[1][lmax];
		arr[1][lmax] = 0;
		arr[1][lmax+1] = 0;
		arr[1][lmax-1] = 0;
		arr[0][lmax] = 0;
	}
	//printf("maxs : %d\n",maks);
	return flag;
}
