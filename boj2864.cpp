#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
using namespace std;
string s1,s2;
int a1,a2;
int b1,b2;
int main(void)
{
	cin >> s1 >> s2;
	int mult = 1;
	for(int i = s1.length()-1; i>=0; i--)
	{
		if(s1[i] == '6' || s1[i] == '5')
		{
			a1 += 5 * mult;
			a2 += 6 * mult;
		}
		else{
			a1+= (s1[i] - '0') * mult;
			a2+= (s1[i] - '0') * mult;
		}	
		mult*=10;
	}
	mult = 1;
	for(int i = s2.length()-1; i>=0; i--)
	{
		if(s2[i] == '6' || s2[i] == '5')
		{
			b1 += 5 * mult;
			b2 += 6 * mult;
		}
		else{
			b1+= (s2[i] - '0') * mult;
			b2+= (s2[i] - '0') * mult;
		}	
		mult*=10;
	}
	
	printf("%d %d\n",a1+b1,a2+b2);


	return 0;
}

