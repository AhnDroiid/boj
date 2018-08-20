#include <iostream>
#include <cstdio>


void gcd(int n1 ,int n2);
void lca(int n1, int n2);
int result1 = 0;
int result2 = 0;

int n1,n2;
int main(void)
{
	scanf("%d %d",&n1,&n2);
	
	if(n1 > n2) gcd(n1,n2);
	else gcd(n2, n1);
	
	printf("%d %d",result1,n1*n2/result1);
	return 0;
}

void gcd(int n1 ,int n2)
{
	int ret = n1 % n2;
	if(ret == 0)
	=
		result1 = n2;
		return;
	}	
	else
	{
		gcd(n2,ret);
	}
}


