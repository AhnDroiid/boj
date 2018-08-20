#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int N,M;


typedef struct __Node
{
	int data;
	struct __Node *next;
}Node;

Node * arr;
int main(void)
{
	//printf("?\n");
	scanf("%d %d",&N,&M);
	arr = (Node*)malloc(sizeof(Node) * (N+1));
	for(int i=1; i<=N; i++)
	{
		arr[i].data = 0;
		arr[i].next = NULL;
	}	
	int from,to;
	for(int i=0; i<M; i++)
	{
		scanf("%d %d",&from,&to);
		arr[to].data += 1;
		Node * newnode = (Node*)malloc(sizeof(Node));
		newnode->data = to;
		newnode->next = arr[from].next;
		arr[from].next = newnode;
	}
	int queue[N+1];
	int first = 0;  
	int last  = 0;
	for(int i=1; i<N+1; i++)
	{
		if(arr[i].data == 0)
		{
			arr[i].data--;
			queue[last++] = i;
		}
	}
	Node * cur;
	while(first != last)
	{
		//printf("?\n");
		int out = queue[first++];
		printf("%d ",out);
		cur = arr[out].next;
		while(cur!= NULL)
		{
			arr[cur->data].data--;
			cur=cur->next;
		}
		//printf("?\n");
		for(int i=1; i<N+1; i++)
		{
			if(arr[i].data == 0)
			{
				arr[i].data--;
				queue[last++] = i;
			}
		}
	}
	printf("\n");
	return 0;
}
