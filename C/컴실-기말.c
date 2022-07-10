#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct score {
	int a, b; 
}score;

int find(score *p,int n) {
	int ans = 0;
	int max1 = p[0].a, max2 = p[0].b;

	
	int i, j;
	for (j = 0; j < n; j++) {
		if (max1 < p[j].a && max2 < p[j].b) {
			max1 = p[j].a; max2 = p[j].b;
		}
		
	}
	for (i = 0; i < n; i++) {
		if (p[i].a < max1 && p[0].b < max2) continue;
		else ans++; 
	}

	return ans; 
}

int main(void)
{
	int t, n; 

	scanf("%d", &t);
	scanf("%d", &n);

	int i, j;
	score* p = (score *)malloc(sizeof(score) *n); // 2차원 배열로만들고 진행 


	for (i = 0; i < t; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d %d", &p[j].a, &p[j].b);
		}
	}
	int ans1 = find(p,n);
	printf("%d", ans1);
	return 0;
}