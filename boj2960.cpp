#include <iostream>
#include <cmath>
#include <cstdio>



int main(void)
{
	int n;
	int k;
	int cnt = 0;
	int sol;
	scanf("%d %d",&n,&k);
	bool * PrimeNum = new bool[n+1];
	for(int i=2; i<=n; i++) PrimeNum[i] = true;
	
	for(int i=2; i<=n; i++)
	{
		if(PrimeNum[i])
		{
			cnt++;
			//printf("%d ",i);
			if(cnt == k)
			{
				sol = i;
			
			} 
			for(int j = i*i; j<=n; j+=i) 
			{
				if(PrimeNum[j])
				{
					PrimeNum[j] = false;
				//	printf("%d ",j);
					cnt++;
				//printf("%d\n",cnt);
					if(cnt == k)
					{
						//printf("%d %d \n", cnt, k);
						sol = j;
						
					} 
				}
			}
		}
	}
	//printf("\n");
	printf("%d\n",sol);
	return 0;
}
