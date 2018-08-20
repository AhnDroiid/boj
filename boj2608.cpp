#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int translateFromWord(char * str);
int translateFromNum(int num);

typedef enum {IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900} tw;
typedef enum {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000}ta;
int main(void)
{
	char * one = (char*)malloc(sizeof(16));
	char * two = (char*)malloc(sizeof(16));
	scanf("%s",one);
	scanf("%s",two);
	int sum = 0;
	sum += translateFromWord(one);
	sum += translateFromWord(two);
	
	printf("%d\n",sum);
	
	return 0;
}

int translateFromWord(char * str)
{
	int sum = 0;
	int len = strlen(str);
	int i,j;
	tw earr[6] = {IV,IX,XL,XC,CD,CM};
	ta e;
	int flag = 0;
	char * temp = (char*)malloc(sizeof(3));
	temp[2] = 0;
	char * arr[6] = {"IV","IX","XL","XC","CD","CM"};
	for(i =0; i<len; i++)
	{
		flag = 0;
		temp[0] = str[i];
		temp[1] = str[i+1];
		for(j =0 ; j<6; j++)
		{
			if(!strcmp(temp,arr[j]))
			{
				sum+=earr[j];	
				i+=1;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			continue;
		e = (ta)'I';
		printf("%d\n",e);
		sum += e;
		
	}
	return sum;
}
int translateFromNum(int num)
{
	
}
