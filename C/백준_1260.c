#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct  node* link;
	int data;
	int size;
}node;

void push(node *head, int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = head->link;

	head->link = newNode; 
	head->size++;
}
int pop(node  *head)
{
	if (head->size == -1) return;
	head->size--;
	int data = head->link->data;
	node *temp = head->link;
	head->link = temp->link;
	temp = NULL; 
	free(temp);

	return data;
}

int stack_top(node *head)
{
	if (head->link != NULL) return head->link->data;
	else return -1;
}

void push_q(node *head, int data)
{
	node *temp = head;
	while (temp->link != NULL)
		temp = temp->link;
	
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = NULL;

	temp->link = newNode; 
	head->size++;
}

int graph[1001][1001] = { 0, };

void dfs(int v, int vertices)
{
	int visit[1001] = { 0, };
	int w = 0;
	int flag = 1;
	visit[v] = 1;
	printf("%d ",v);

	node *head = (node *)malloc(sizeof(node));
	head->link = NULL;
	head->size = -1; 
	push(head, v);
	
	while (head->size != -1 ) {
		if (!flag) pop(head);
		v = stack_top(head);
		//printf("v :%d", v);
		if (v == -1) break;
		flag = 0;
		for (w = 1; w <= vertices; w++) {
			if (graph[v][w] && !visit[w]) {
				push(head, w);
				visit[w] = 1;
				printf("%d ", w);
				v = w; 
				flag = 1;
				break;
			}
		}
	}
}

void bfs(int v, int vertices)
{
	int visit[1001] = { 0, };
	int w = 0;
	int flag = 1;
	visit[v] = 1;
	printf("%d ", v);

	node *head = (node *)malloc(sizeof(node));
	head->link = NULL;
	head->size = -1;

	push_q(head, v);

	while (head->size != -1) {
		if (!flag) v=pop(head);
		v = stack_top(head);
		//printf("v :%d", v);
		if (v == -1) break;
		flag = 0;
		for (w = 1; w <= vertices; w++) {
			if (graph[v][w] && !visit[w]) {
				push_q(head, w);
				visit[w] = 1;
				printf("%d ", w);
				flag = 1;
			}
		}
	}
}

int main(void)
{
	int vertices, edges, vertex, i, j;
	scanf("%d %d %d", &vertices, &edges, &vertex);

	while (edges--) {
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	dfs(vertex, vertices);
	printf("\n");
	bfs(vertex, vertices);

	return 0;
}