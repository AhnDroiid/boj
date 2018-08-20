#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <list>
#include <set>
#include <functional>
using namespace std;
int n;
int A[4001];
int B[4001];
int C[4001];
int D[4001];
int AB[4001 * 4001];
int CD[4001 * 4001];
int idx = 0;
int ccount = 0;
int binary(int val)
{
	int left = 0;
	int right = idx;
	int mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(CD[mid] < val) left = mid + 1;
		else if(CD[mid] == val) return mid;
		else right = mid-1;
	}
	
	return -1;
	//printf("ans : %d\n",ans);
	return ans;
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i <= n ; i++)
	{
		scanf("%d %d %d %d",A+i,B+i,C+i,D+i);
	}
	
	for(int i = 1; i <= n ; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			AB[idx] = A[i] + B[j];
			CD[idx] = C[i] + D[j];
			idx++;
		}
	}
	//printf("idx : %d\n",idx);
	sort(CD,CD+idx);
	for(int i = 0; i< idx; i++)
	{
		int Toright = binary(AB[i] * -1);
		int Toleft = Toright-1;
		if(Toright == -1) continue;
		while(CD[Toright] == (AB[i] * -1) && Toright < idx)
		{ 
			Toright++;
			ccount++;
		}
		while(CD[Toleft] == (AB[i] * -1) && Toleft >= 0)
		{
		 	Toleft--;
		 	ccount++;
		}
	}
	printf("%d\n",ccount);
	return 0;
}

