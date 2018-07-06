#include <iostream>
#define FOR(i,b) for(int i = 0; (i) < (b) ; i++)
using namespace std;

void Swap(int *a, int *b);


int main(void)
{
	int num;
	int i,j;
	cin >> num;
	int * arr = new int[num];
	int result[num];
	FOR(i,num) cin >> arr[i];
	FOR(i,num) result[i] = i+1;
	FOR(i,num)
	{
		for(j = i; j>=i-arr[i]+1; j--)
		{
			Swap(&result[j],&result[j-1]);
		}
	}
	FOR(i,num) cout << result[i] << ' ';
	cout <<endl;
	return 0; 
}

void Swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}
