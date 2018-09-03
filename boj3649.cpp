#include <bits/stdc++.h>
using namespace std;

int x,n;
bool flag = false;
vector<int> origin;
int idx;
int binarySearch(int left, int right,int val)
{
	
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(val > origin[mid])
		{
			
			left = mid + 1;
		}
		else if(val == origin[mid])
		{
			if(idx != mid)
				return mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main(void)
{
	while(scanf("%d %d",&x,&n) == 2)
	{
		x *= 10000000;
		origin.clear();
		flag= false;
		for(int i = 0 ; i<n; i++)
		{
			int a;
			scanf("%d",&a);
			origin.push_back(a);
		}
		sort(origin.begin(),origin.end());
		for(idx = 0; idx<origin.size(); idx++)
		{
			int tmp = binarySearch(0,origin.size()-1,x-origin[idx]);
			if(tmp != -1)
			{
				printf("yes %d %d\n",origin[idx],x - origin[idx]);
				flag = true;
				break;
			}
		}
		if(!flag)
			printf("danger\n");
	
	}



	return 0;
}

