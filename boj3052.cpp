#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int *retArr;


int main(void)
{
	int tmp;
	int sol = 0;
	retArr = new int[42];
	//memset(retArr,0,sizeof(int) * 42);
	for(int i=0;i<10;i++)
	{
		scanf("%d",&tmp);
		cout <<"it's: "<< tmp %42 <<"and"<<retArr[tmp%42]<< endl;
		if( (retArr[tmp%42]++) == 0)
			sol++;
		
	}
	cout << sol << endl;
	return 0;
}
