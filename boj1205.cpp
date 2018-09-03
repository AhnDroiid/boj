#include <bits/stdc++.h>
using namespace std;

int n,score,p;
vector<int> v;


int main(void)
{

	scanf("%d %d %d",&n,&score,&p);
	if(n == 0)
	{
		printf("1\n");
		return 0;
	}
	for(int i = 0 ; i<n; i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end(),greater<int>());
	int minn = v[v.size()-1];
	if(abs(n-p) == 0 && minn >= score)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		v.push_back(score);
		sort(v.begin(),v.end(),greater<int>());	
		int val = v[0];
		int rank = 1;
		if(abs(n-p) == 0) v.pop_back();
		for(int i = 0; i<v.size(); i++)
		{
			
			if(val != v[i])
			{
				val = v[i];
				if(v[i] == score)
				{
					printf("%d\n",i+1);
					return 0;
				}
				rank++;
			}
			else
			{
				if(v[i] == score)
				{
					printf("%d\n",rank);
					return 0;
				}
			}
			
		}
		printf("%d\n",rank);
		
	}
	



	return 0;
}

