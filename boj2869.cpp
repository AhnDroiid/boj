#include <iostream>
#include <cstdio>


int a,b,v;
int sol = 0;
int main(void)
{
	scanf("%d %d %d",&a,&b,&v);
	int ret = v - a;
	int diff = a - b;
	if(ret / diff == 0) sol++;
	else if(ret / diff != 0  && ret % diff != 0) sol+=(ret/diff + 1);
	else sol+=(ret / diff);
	printf("%d\n",sol+1);
	return 0;
}
