#include <stdio.h>
#include <string.h>
int check(char * n)
{
	if(strcmp(n,"pi") == 0 || strcmp(n,"ka") ==0 || strcmp(n,"chu") == 0)
		return 1;
	else
		return 0;
}



int main(void)
{
	char n[5000];
	scanf("%s",n);
	int len = strlen(n);
	int i =0;
	while(1)
	{
		if(len == 1) 
		{
			printf("NO\n");
			return 0;
		}
		if(i>=len) 
		{
			printf("YES\n");
			return 0;
		}
		if(n[i] == 'p')
		{
			if((i+1) != len)
			{
				if(n[i+1] == 'i')
				{
					i+=2;
					continue;
				}
				else
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				printf("NO\n");
				return 0;
			}
		}
		else if(n[i] == 'k')
		{
			if((i+1) != len)
			{
				if(n[i+1] == 'a')
				{
					i+=2;
					continue;
				}
				else
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				printf("NO\n");
				return 0;
			}
		}
		else if(n[i] == 'c')
		{
			if((len-1-i) >=2)
			{
					if(n[i+1] == 'h' && n[i+2] == 'u')
				{
					i+=3;
					continue;
				}
				else
				{
					printf("NO\n");
					return 0;
				}
			}
			else
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		{
			printf("NO\n");
			return 0;
		}
	}
}	
