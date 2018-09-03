#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int color[100000];
int num[100000];
vector<int> nq;
vector<char> cq;
int result = -1;
bool check = false;
void one(void);
void sec(void);
void th(void);
void fr(void);
void fif(void);
void six(void);
void sev(void);
void ei(void);
void nine(void);
void final(void);
string c;
int n;

int main(void)
{
	cq.push_back('.');
	nq.push_back(-123);
	for(int i =0; i<5; i++)
	{
		cin >> c >> n;
		color[c[0]]++;
		num[n]++;
		cq.push_back(c[0]);
		nq.push_back(n);
	}
	final();
	printf("%d\n",result);
	
	
	return 0;
}
// 1st case
void one(void)
{
	int tmp[6];
	for(int i = 1; i<=5; i++)
		tmp[i] = nq[i];
	sort(tmp+1,tmp+6);
	bool flag = true;
	
	for(int i = 2; i<=5; i++)
	{
		if(tmp[i] != tmp[i-1] + 1) flag = false; 
	}
	for(int i ='A'; i<='Z'; i++)
	{
		if(color[i] == 5 && flag)
		{
			result = max(result,900+tmp[5]);
			check = true;
		}
	}
}
//2nd case
void sec(void)
{
	for(int i =1; i<=9; i++)
	{
		if(num[i] == 4)
		{
			result = max(result,800+i);
			check = true;
		}
	}
}

//3rd case
void th(void)
{
	int three = -1;
	int two = -1;
	for(int i =1; i<=9; i++)
	{
		if(num[i] == 3) three = i;
		else if(num[i] == 2) two = i;
	}
	if(three != -1 && two != -1)
	{
		result = max(result,three * 10 + two + 700);
		check = true;
	}
}

//4th case
void fr(void)
{
	int tmp[6];
	for(int i =1 ; i<=5;i++)
		tmp[i] = nq[i];
	sort(tmp+1,tmp+6,greater<int>());
	for(int i = 'A'; i<='Z'; i++)
	{
		if(color[i] == 5)
		{
			result= max(result,600 + tmp[1]);
			check = true;
		}
	}
}
//5th case
void fif(void)
{
	int tmp[6];
	for(int i = 1; i<=5; i++)
		tmp[i] = nq[i];
	sort(tmp+1,tmp+6);
	bool flag = true;
	
	for(int i = 2; i<=5; i++)
	{
		if(tmp[i] != tmp[i-1] + 1) flag = false;
	}
	if(flag)
	{
		result = max(result,500 + tmp[5]);
		check = true;
	}
}
//6th case
void six(void)
{
	bool flag = true;
	int ccount = 0;
	for(int i =1; i<9; i++)
	{
		if(num[i] == 1) ccount++;
	}
	if(ccount != 2) flag = false;
	for(int i =1; i<=9; i++)
	{
		if(num[i] == 3 && flag)
		{
			result = max(result,400 + i);
			check = true;
		}
	}
}
//7th case
void sev(void)
{

	int two[2] = {-1,-1};
	int idx = 0;
	for(int i = 1; i<=9; i++)
	{
		if(num[i] == 2)
			two[idx++] = i;
	}
	if(two[0] != -1 && two[1] != -1)
	{
		sort(two,two+2);
		result = max(result,10 * two[1] +two[0] + 300);
		check = true;
	}
}
//8th case
void ei(void)
{
	bool flag = true;
	int ccount = 0;
	for(int i = 1; i<=9; i++)
		if(num[i] == 1) ccount++;
	if(ccount != 3) flag = false;
	for(int i = 1; i<=9; i++)
	{
		if(num[i] == 2 && flag)
		{
			result = max(result,200 + i);
			check = true;
		}
	}
}

//9th case
void nine(void)
{
	if(!check)
	{
		sort(nq.begin(),nq.end(),greater<int>());
		result = max(result,100 + nq[0]);
	}
}
void final(void)
{
	one();
//	printf("result : %d\n",result);
	sec();
//	printf("result : %d\n",result);
	th();
//	printf("result : %d\n",result);
	fr();
//	printf("result : %d\n",result);
	fif();
//	printf("result : %d\n",result);
	six();
//	printf("result : %d\n",result);
	sev();
//	printf("result : %d\n",result);
	ei();
//	printf("result : %d\n",result);
	nine();
//	printf("result : %d\n",result);
	
}
