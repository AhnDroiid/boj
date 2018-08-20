#include <iostream>
#include <cmath>
#include <cstdio>



int main(void)
{
	int n;
	int m;
	int sol;
	scanf("%d %d",&m,&n);
	bool * PrimeNum = new bool[n];
	for(int i=2; i<=n; i++) PrimeNum[i] = true;
	
	for(int i=2; i<=sqrt(n); i++)
	{
		if(PrimeNum[i])
		{
			for(int j = i*i; j<=n; j+=i) PrimeNum[j] = false;
		}
	}
	for(int i=2; i<=n; i++)
		if(PrimeNum[i] && i>=m) printf("%d\n",i);
		
	return 0;
}
