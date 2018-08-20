#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int N;
char arr[65][65];


string solve(int rowStart,int colStart,int rowEnd,int colEnd)
{
	//printf("?\n");
	int rowHalf = (rowEnd-rowStart)/2;
	int colHalf = (colEnd-colStart)/2;
	//printf("str:%d , stc:%d, halfr : %d , halfc: %d , stend: %d, cend: %d\n",rowStart,colStart,rowHalf,colHalf,rowEnd,colEnd);
	if(rowHalf < 1 || colHalf < 1)
	{
		if(arr[rowStart][colStart] == '1' && arr[rowEnd][colStart] == '1' && arr[rowStart][colEnd] == '1' && arr[rowEnd][colEnd] == '1')
			return "1";
		if(arr[rowStart][colStart] == '0' && arr[rowEnd][colStart] == '0' && arr[rowStart][colEnd] == '0' && arr[rowEnd][colEnd] == '0')
			return "0";
		return string("(") + string(1,arr[rowStart][colStart]) + string(1,arr[rowStart][colEnd]) + string(1,arr[rowEnd][colStart]) + string(1,arr[rowEnd][colEnd]) + string(")");
	}
	
	string upperLeft = solve(rowStart,colStart,rowStart+rowHalf,colStart+colHalf);
	string upperRight = solve(rowStart,colStart+colHalf+1,rowStart+rowHalf,colEnd);
	string lowerLeft = solve(rowStart+rowHalf+1,colStart,rowEnd,colStart+colHalf);
	string lowerRight = solve(rowStart+rowHalf+1,colStart+colHalf+1,rowEnd,colEnd);
	
	if(upperLeft == "0" && upperRight == "0" && lowerLeft == "0" && lowerRight == "0")
	{
		return string("0");
	}
	if(upperLeft == "1" && upperRight == "1" && lowerLeft == "1" && lowerRight == "1")
	{
		return string("1");
	}
	return string("(") + upperLeft + upperRight + lowerLeft + lowerRight + string(")");
	
}
int main(void)
{
	scanf("%d",&N);
	char * temp = (char*)malloc(N+1);
	for(int i=1; i<=N; i++)
	{
		while(getchar() != '\n')
			;
		scanf("%s",temp);
		for(int j=0; j<N; j++)
		{
			//printf("temp: %c\n",temp[j]);
			arr[i][j+1] = temp[j];
		}
	}
	cout << solve(1,1,N,N) << endl;
	
	return 0;
}
