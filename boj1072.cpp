#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <cmath>
using namespace std;

int main(void)
{
	long int x,y;
	while(scanf("%ld %ld",&x,&y) != EOF)
	{
		long int rate = (long int)((y+0.0) / x * 100);
		long double minimum;
		long long diff = x - y;
		minimum = ((rate+1) * x - (y*100) + 0.0) / (100-(rate+1));
		//printf("m : %Lf\n",minimum);
		if(minimum <= 0 || minimum >= 99) printf("-1\n");
		else printf("%ld\n", (long int)ceil(minimum));
	}
	
	


	return 0;
}

