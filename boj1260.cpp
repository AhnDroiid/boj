#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
int n,m,v;
int ** arr;
int queue[10000000];
int first = 0;
int last = 0;
void Print(void)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void BFS(int v)
{
	queue[0] = v, last++;
	int visited[n];
	memset(visited,0,sizeof(int) * n);
	while(first != last)
	{
		int out = queue[first++];
		visited[out-1] = 1;
		printf("%d ",out);
		for(int i=0; i<n; i++)
		{
			//printf("i: %d\n",i);
			if(!visited[i] && arr[out-1][i] == 1)
			{
				//printf("inserted\n",i);
				queue[last++] = i+1;
				visited[i] = 1;
			}
		}
	}
	printf("\n");
	return;
}
void DFS(int v)
{
	int stack[100000];
	int visited[n];
	int top = -1;
	stack[++top] = v;
	memset(visited,0,sizeof(int) * n);
	visited[v-1] = 1;
	int out = stack[top--];
	printf("%d ",out);
	while(1)
	{
		for(int i=n-1; i>=0; i--)
		{
			//printf("top : %d\n",top);
			if(!visited[i] && arr[out-1][i] == 1)
			{
				stack[++top] = i+1;
			}
		}
		if(top == -1) break;
		out = stack[top--];
		if(!visited[out-1])
		{
		 	printf("%d ",out);
		 	visited[out-1] = 1;
		}
	}
	printf("\n");
}
int main(void)
{
	scanf("%d %d %d",&n,&m,&v);
	arr = (int**)malloc(sizeof(int*) * n);
	
	for(int i=0; i<n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
		memset(arr[i],0,sizeof(int) * n);
	}
	for(int i=0; i<m; i++)
	{
		int from,to;
		scanf("%d %d",&from,&to);
		arr[from-1][to-1] = 1;
		arr[to-1][from-1] = 1;
	}
	//Print();
	DFS(v);
	BFS(v);
	
	
	return 0;
}
