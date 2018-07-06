#include <stdio.h>



int main(void)
{
	int count = 0;
	int vertexNum;
	int edgeNum;
	int vertex_one,vertex_two;
	int i,turn;
	turn = 0;
	
	scanf("%d",&vertexNum);
	scanf("%d",&edgeNum);
	
	int arr[vertexNum][vertexNum] = {0};
	int visitvertex[vertexNum] = {0};
	int stack[vertexNum+1] = {0};
	for(int j = 0; j<vertexNum; j++)
	{
		for(int m=0; m<vertexNum; m++)
		{
			arr[j][m] = 0;
		}
	}
	
	for( i=0; i<edgeNum; i++)
	{
		scanf("%d %d",&vertex_one,&vertex_two);
		arr[vertex_one-1][vertex_two-1] = 1;
		arr[vertex_two-1][vertex_one-1] = 1;
	}
	
	stack[1] = 1;
	turn++; 
	while(turn != 0)
	{
		int ind = stack[turn];
		turn--;
		visitvertex[ind-1] = 1;
		
		for(i=0; i<vertexNum; i++)
		{
			if(arr[ind-1][i] == 1 && visitvertex[i] != 1)
			{
				turn++;
				stack[turn] = i+1;
			}
		}
	}
	/*for(i=0; i<vertexNum; i++)
	{
		for(int m=0; m< vertexNum; m++)
			printf("%d ",arr[i][m]);
		printf("\n");
	}
	printf("\n");
	for(i=0; i<vertexNum; i++)
		printf("%d ",visitvertex[i]);
	printf("\n\n");*/
	for(i =1; i< vertexNum; i++)
	{
		if(visitvertex[i]) count++;
	}
	printf("%d\n",count);
	
	
	return 0;
}
