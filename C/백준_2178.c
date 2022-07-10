#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
	int size; 
}node;

void push(node *n, int data)
{
	node * cur = n;
	while (cur->link != NULL)
		cur = cur->link;

	node *newNode = (node *)malloc(sizeof(node));
	newNode->link = NULL;
	cur->link = newNode;
	newNode->data = data;

	n->size++; 
}

int pop(node *n)
{
	if (n->size == -1) return -1;
	
	n->size--;

	node *temp = n->link;
	int data = temp->data;
	n->link = temp->link;
	temp = NULL;

	free(temp); 
}

int top(node *n)
{
	if (n->size == -1) return -1; 
	else return n->link->data; 
}
void bfs(int **maze,int n, int m)
{
	int ans = 0;
	int temp;
	int x[4] = { 1,0,0,-1 };
	int y[4] = { 0 ,-1,1,0 };

	node *head = (node *)malloc(sizeof(node));
	head->link = NULL;
	head->size = -1;

	int **visit = (int **)malloc(sizeof(int *) *n);
	for (int i = 0; i < n; i++)
		visit[i] = (int *)malloc(sizeof(int) *m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (maze[i][j]) visit[i][j] = 10000 * (i)+j;
			else visit[i][j] = 0;
		}

	push(head, visit[0][0]);
	maze[0][0] = 0;
	int i, j;

	while (head->size != -1) {
		temp = top(head);
		i = temp / 10000;
		j = temp % 10000;
	//	printf("current : %d %d and ", i, j);
		if (j == m - 1 && i == n - 1) break;
		for (int w = 0; w < 4; w++) {
			if (i + y[w] >= 0 && j + x[w] >= 0 && i + y[w] < n && j + x[w] < m) {
				if (maze[i + y[w]][j + x[w]]) {
			//		printf("move to : %d %d\n", i + y[w], j + x[w]);
					push(head, visit[i + y[w]][j + x[w]]);
					maze[i + y[w]][j + x[w]] = 0;
					visit[i + y[w]][j + x[w]] = temp;
				}
			}
		}
		pop(head);
	}

	//printf("Check\n");
//	printf("%d %d", i, j);	

	while (i != 0 || j != 0) {
		temp = visit[i][j];
		//printf("%d\n", temp);
		ans++;
		i = temp / 10000;
		j = temp % 10000;
	}
	ans++;
	printf("%d", ans);
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int **visit = (int **)malloc(sizeof(int *) *n);
	for (int i = 0; i < n; i++)
		visit[i] = (int *)malloc(sizeof(int) *m);

	char k[101];
	for (int i = 0; i < n; i++) {
		scanf("%s", k);

		for (int j = m - 1; j >= 0; j--) {
			visit[i][j] = (int)(k[j] - '0');
			//printf("%d", visit[i][j]);
		}
		//printf("\n");
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", visit[i][j]);
		}
		printf("\n");
	}
	*/
	bfs(visit, n, m);

	return 0;
}