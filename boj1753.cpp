#include <iostream>
#include <cstdio>
#include <cstring>
// Adjacent List version Dijkstra O(V^2 + E)  
const int INF = 987654321;
int V,E;
int k;

typedef struct __Node
{
	int data;
	int weight;
	struct __Node * next;
}Node;
Node arr[20001];
int memo[20001];
int visited[20001];
void Insert(int src,int dst,int weight)
{
	Node * cur = &arr[src];
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	//printf("?\n");
	Node * newnode = new Node;
	newnode->data = dst;
	newnode->weight = weight;
	newnode->next = NULL;
	cur->next = newnode;
}
int target;
int min;
int minVal;

void Dijkstra(void)
{
	target = k;
	
	while(1)
	{
		visited[target] = 1;
		Node * cur = arr[target].next;
		min = INF;
		minVal = INF;
		while(cur != NULL)
		{
			if(memo[cur->data] == INF) memo[cur->data] = memo[target] + cur->weight;
			else if(memo[cur->data] > memo[target] + cur->weight) memo[cur->data] = memo[target] + cur->weight;
			
			cur = cur->next;
		}
		for(int i =1; i<=V; i++)
		{
			if(memo[i] != INF && !visited[i] && minVal > memo[i])
			{
				min = i;
				minVal = memo[min];
			}
		}
		if(min == INF) break;
		target = min;
		
	}
}
int main(void)
{
	for(int i=1; i<=20000; i++)
	{
		arr[i].next = NULL;
		memo[i] = INF;
	}
	scanf("%d %d",&V,&E);
	scanf("%d",&k);
	memset(visited,0,sizeof(int) * 20001);
	int src,dst,weight;
	for(int i =0; i<E; i++)
	{
		scanf("%d %d %d",&src,&dst,&weight);
		//printf("hi\n");
		Insert(src,dst,weight);
	}
	memo[k] = 0;
	Dijkstra();
	for(int i=1; i<=V;i++)
	{
		if(memo[i] >= INF) printf("INF\n");
		else printf("%d\n",memo[i]);
	}
	return 0;
}
