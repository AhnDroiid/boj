#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int tc;
int n;
deque < pair<int,int > > data;
int main(void)
{

	scanf("%d",&tc);
	for(int i = 0 ; i <tc; i++)
	{
		scanf("%d",&n);
		data.clear();
		int ccount = 1;
		int maks;
		for(int i = 1; i<=n; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			data.push_back(make_pair(a,b));
		}
		sort(data.begin(),data.end());
		maks = data[0].second;
		for(int i = 1; i<data.size(); i++)
		{
			if(data[i].second < maks)
				ccount++;
			maks = min(maks,data[i].second);
		}
		printf("%d\n",ccount);
	}
	


	return 0;
}

