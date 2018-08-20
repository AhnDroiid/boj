#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int r,c;
int **arr;
char * temp;

bool check(int size, int i, int j);
int main(void)
{
	scanf("%d %d",&r,&c);
	
	arr = (int**)malloc(sizeof(int*) * r);
	temp = (char*)malloc(c);
	for(int i=0; i<r; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * c);
	}
	
	for(int i=0; i<r; i++)
	{
		scanf("%s",temp);
		for(int j=0; j<c; j++)
		{
			arr[i][j] = temp[j] - '0';
		}	
	}
	if(r < c)
	{
		for(int i=r; i>=2; i--)
		{
			for(int j=0; j<r; j++)
			{
				for(int b = 0; b <c; b++)
				{
					if(check(i,j,b))
					{
						printf("%d\n",i);
						return 0;
					}
				}
			}
			
		}
	} 
	else
	{
		for(int i=c; i>=2; i--)
		{
			for(int j=0; j<r; j++)
			{
				for(int b = 0; b <c; b++)
				{
					if(check(i,j,b))
					{
						printf("%d\n",i);
						return 0;
					}
				}
			}
			
		}
	}
	printf("%d\n",-1);
	return 0;

}


bool check(int size, int i,int j)
{
	bool flag = true;
	float middleX;
	float middleY;
	int EvenstartIdx= i;
	int EvenendIdx = i+(size/2)-1;
	int OddstartIdx= i;
	int OddendIdx = i+(size/2);
	if(i+size <= r && j+size <= c)
	{
		//cout << i << "  " << j << endl;
		middleX = (float)(i+(size-1)/2.0);
		middleY = (float)(j+(size-1)/2.0);
		//cout <<"middle" << middleX <<"  " << middleY << endl;
		if(size % 2 == 0) // Â¦¼ö 
		{	
			for(int n =EvenstartIdx; n<=EvenendIdx; n++)
			{
				for(int m=j; m<=j+(size-1); m++)
				{
					//cout <<"here"<< (int)(middleX+(middleX-n))<<" " <<(int)(middleY+(middleY-m)) << endl;
				//	cout << arr[n][m] <<" "<<arr[(int)(middleX+(middleX-n))][(int)(middleY+(middleY-m))]<< endl;
					if(arr[n][m] != arr[(int)(middleX+(middleX-n))][(int)(middleY+(middleY-m))] )
						flag = false;
				}
			}
		}
		else // È¦¼ö
		{
				for(int n =OddstartIdx; n<=OddendIdx; n++)
				{
					for(int m=j; m<=j+(size-1); m++)
					{
						if(arr[n][m] != arr[(int)(middleX+(middleX-n))][(int)(middleY+(middleY-m))])
							flag = false;
					}
				}
		}
	}
	else
	{
		flag = false;
	}
	//if(flag == true)
	//	cout << i << "  " << j << endl;
	return flag;
}
