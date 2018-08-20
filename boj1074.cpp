#include <stdio.h>
#include <time.h>


int N,r,c;
int count = 0;
int result = 0;
int flag = 0;
void func(int n1, int n2, int n)
{	
	
	if( flag == 1) return;
	if(n1+n < r || n2+n < c)
	{
		count+= (n*n);
		return;
	}
	if(n1 == r && n2 == c)
	{
		 result = count;
		 flag = 1;
		 return;
	}
	if(n == 1)
	{
		count++;
	}
	else
	{
		func(n1,n2,n/2);
		func(n1,n2+n/2,n/2);
		func(n1+n/2,n2,n/2);
		func(n1+n/2,n2+n/2,n/2);
	}
	
	
	return;
	
}

int main(void)
{
	scanf("%d %d %d",&N,&r,&c);
	int length = 1;
	
	//double start,end;
	//start = clock();
	func(0,0,length<<(N));
	printf("%d\n",result);
	//end = clock();
	//printf("%f",(end-start) / CLOCKS_PER_SEC);
	return 0;
		
}
