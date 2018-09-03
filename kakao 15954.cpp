#include <bits/stdc++.h>
using namespace std;
vector<double> val;
vector<double> square;
vector<double> pyuncha;
int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	val.push_back(0);
	square.push_back(0);
	for(int i = 0; i<n; i++)
	{
		double a;
		scanf("%lf",&a);
		val.push_back(a);
		square.push_back(0);
	}
	for(int i = 1; i<=n; i++)
	{
		square[i] = square[i-1] + (val[i] * val[i]); 
		val[i] += val[i-1];
	}
	for(int K = k; K <=n; K++)
	{
		for(int i = 0 + K; i<=n; i++)
		{
			double tmp;
			double average = (val[i] - val[i-K]) / K;
			tmp = (square[i] - square[i-K]) + (-2 * (val[i] - val[i-K])) * average + K *(average * average);
			pyuncha.push_back(sqrt(tmp/K));
		}
	}
	sort(pyuncha.begin(),pyuncha.end());
	printf("%f\n",pyuncha[0]);
	return 0;
}

