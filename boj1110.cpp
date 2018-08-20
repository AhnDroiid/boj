#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int n;
int sol = 1;
int tmp;
int tmp2;
char * two;
char init1;
char init2;
int main(void)
{
	scanf("%d",&n);
	two = new char[3];
	memset(two,0,3);
	if(n>=0 && n<=9)
	{
		two[1] = n+'0';
		two[0] = 0+'0';
	}
	else
	{
		two[1] = (n%10) + '0';
		n/=10;
		two[0] = n+'0';
	}
	init1= two[0], init2 = two[1];
	tmp = two[1]-'0';
	tmp2 = ((two[0]-'0') +(two[1]-'0')) % 10;
	two[1] = tmp2+'0';
	two[0]= tmp+'0';
	//printf("%s\n",two);
	while(init1 != two[0] || init2 != two[1])
	{
		tmp = two[1]-'0';
		tmp2 = ((two[0]-'0') +(two[1]-'0')) % 10;
		two[1] = tmp2+'0';
		two[0]= tmp+'0';
		//printf("%s\n",two);
		sol++;
	}
	//printf("%s\n",two);
	printf("%d\n",sol);
	return 0;	
}
