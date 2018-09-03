#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n,m;
int arr[1001][1001];
int val[1001][1001];
int main(void)
{
	scanf("%d %d",&n,&m);
	int result = 0;
	string tmp;
	for(int i =1; i<=n; i++)
	{
		cin >> tmp;
		for(int j = 1; j<=m; j++)
		{
			if(tmp[j-1] == '0') continue;
			//val[i][j] = tmp[j-1]-'0';
			arr[i][j] = arr[i][j-1] + (tmp[j-1]-'0');
		}
	}
/*	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}*/
	for(int i = 1; i<=n; i++)
	{
		for(int j = m; j>=1; j--)
		{
			int tmp = arr[i][j];
			if(tmp == 0) continue;
			if(tmp == 1)
			{
				result = max(result,tmp);
				continue;
			}
			int sum = 0;
			if(tmp != 0) sum = 1;
			
			int uidx = i-1;
			int didx = i+1;
			while(sum < tmp && uidx >= 1)
			{
				if(arr[uidx][j] < tmp) break;
				if(arr[uidx--][j] >= tmp)
				{
					sum++;
				}
			}
			if(sum == tmp)
				result = max(result,tmp);
			else
			{
				while(sum < tmp && didx <= n)
				{
					if(arr[didx][j] < tmp) break;
					if(arr[didx++][j] >= tmp)
					{
						sum++;
					}
				}
			}
			if(sum == tmp)
				result = max(result,tmp);
		}
	}
	printf("%d\n",result * result);
 	return 0;
}

