#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> first;
vector<int> fval;
vector<int> second;
vector<int> sval;
int main(void)
{
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);
	first.push_back(4);
	first.push_back(5);
	first.push_back(6);
	
	fval.push_back(5000000);
	fval.push_back(3000000);
	fval.push_back(2000000);
	fval.push_back(500000);
	fval.push_back(300000);
	fval.push_back(100000);
	for(int i = 1; i <first.size(); i++)
	{
		first[i] = first[i] + first[i-1];
	}
	
	
	second.push_back(1);
	second.push_back(2);
	second.push_back(4);
	second.push_back(8);
	second.push_back(16);
	
	sval.push_back(5120000);
	sval.push_back(2560000);
	sval.push_back(1280000);
	sval.push_back(640000);
	sval.push_back(320000);
	for(int i = 1; i <second.size(); i++)
	{
		second[i] = second[i-1] + second[i];
	}
	scanf("%d",&n);
	for(int i = 0 ; i <n; i++)
	{
		int a,b;
		int aval,bval;
		scanf("%d %d",&a,&b);
		if(a == 0 || a > first[first.size()-1]) aval = 0;
		else
		{
			for(int j = 0; j<first.size(); j++)
			{
				if(a <= first[j])
				{
					aval = fval[j];
					break;
				}
			}	
		}
		if(b == 0 || b > second[second.size()-1]) bval = 0;
		else
		{
			for(int j = 0; j<second.size(); j++)
			{
				if(b <= second[j])
				{
					bval = sval[j];
					break;
				}
			}
		}
	
		printf("%d\n",aval + bval);
	}
	return 0;
}

