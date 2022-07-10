#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef  struct node {
	int data;
	struct node* link; 
}node;

void push(node *head, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = NULL;

	node * temp = head;
	head->link = newNode;
	newNode->link = head->link; 
}

void swap(node *node1, node *node2)
{
	int temp;
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

void sort(node *head,int size) {
	node *cur = head;

	// head 노드 사용안하니까 초기화한다.
	cur->data = 0;
	cur = cur->link;

	for (int i = 0; i < size; i++)
	{
		if (cur->link == NULL) break;
		for (int j = 0; j < size - 1 - i; j++)
		{
			// if 문 작성
			if (cur->data < cur->link->data) {
				swap(cur, cur->link);
			}
			cur = cur->link;
		}
		cur = head->link;
	}
}

void free(node *head) {
	node *temp = head;

	while (temp != NULL) {
		temp = head;
		head = head->link;
		free(temp);
	}
}

void print(node *head) {
	node *temp = head;
	while (temp->link != NULL) {
		temp = temp->link;
		if (temp->data == -1) continue;
		printf("%d ", temp->data);
	}
}

void insert(node*head, node *n)
{
	node *temp = head;
	n->link = temp->link;
	head->link = n;
	//printf("%d ", n->data);
}
int main(void)
{
	int n, size = 0;
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		node *head = (node*)malloc(sizeof(node));
		head->link = NULL;
	
		while (1) {
			node *newNode = (node *)malloc(sizeof(node));
			newNode->link = NULL;
			scanf("%d", &newNode->data);
			insert(head, newNode);
			if (newNode->data == -1) break;
		}
		//printf("%d", head->link->data);
		//sort(head,size);
		print(head);
		//free(head);
		size = 0;
	}

	return 0;
}