#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

bool check(char * str, char* std);


int main(void)
{
	int inputnum;
	char * std;
	char * temp;
	std = (char*)malloc(sizeof(100));
	temp = (char*)malloc(sizeof(100));
	scanf("%d",&inputnum);
	scanf("%s",std);
	for(int j =0; j< (inputnum-1); j++)
	{
		scanf("%s",temp);
		if(check(temp,std))
			count++;
			
	}
	printf("%d\n",count);
	
	return 0;
	
	
}

bool check(char * str,char *std)
{
	int len = strlen(str);
	int stdlen = strlen(std);
	int i;
	char c;
	int positive_sum = 0;
	int negative_sum = 0;
	int arr[128] = {0};
	for(i=0; i< len; i++)
	{
		c = str[i];
		arr[c]++;
	}
	
	for(i =0; i<stdlen; i++)
	{
		c = std[i];
		arr[c]--;
	} 
	for(i =0; i< 128; i++)
	{
		if(arr[i] < 0)
		{
			negative_sum += arr[i];
		}
		else
			positive_sum += arr[i];
	}
	if(positive_sum <= 1 && negative_sum >= -1)
		return true;
	return false;
}
