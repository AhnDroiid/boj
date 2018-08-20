#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = 3.141592653589793238462643383279502884197169;
double input;
int main(void)
{
	scanf("%lf",&input);
	printf("%.6lf\n%.6lf\n",(input * input)*pi,(double)2*(input*input));
	
	return 0;
}
