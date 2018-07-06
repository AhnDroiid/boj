#include <stdio.h>


bool Judge(int n);

int main(void)
{
	int input, count;
	scanf("%d",&input);
	
	for(int i = 1; i<= input; i++)
	{
		if(Judge(i))
		{
			printf("n : %d\n",i);
			count++;
		}
		
	}
	
	printf("%d\n",count);
	return 0;
	
}

bool Judge(int n)
{
	
	int first, second, diff;
	first = n % 10;
    n-=first;
	n/=10;
	second = n % 10;
    n-=second;
    n/=10;
	diff = first - second;
	if(n == 0)
	    return true;
	while(n != 0)
	{
		first = second;
		second = n % 10;
        n-=second;
        n/=10;
		if(diff != first - second)
			return false;
        
		
	}
	return true;
}
