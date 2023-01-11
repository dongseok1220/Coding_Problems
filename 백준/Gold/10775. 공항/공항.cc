#include<iostream>
#include <algorithm>
#include <vector>

using namespace std; 

/* 시간초과 
int Find(int x, int *parent) {
	
	while (x != parent[x])
		x = parent[x]; 
	return x; 
}
*/ 


int Find(int x, int* parent) {
	if (x == parent[x]) return x; 
	return parent[x] = Find(parent[x], parent); 
}

int Union(int x, int y) {

}

int main()
{
	int G;
	cin >> G; // 게이트 수 
	int P;
	cin >> P; // 비행기 수 

	int* parent = new int[G+1];

	for (int i = 0; i <= G; i++)
		parent[i] = i; // MakeSet
	int g;
	int ans = 0;
	for (int i = 1; i <= P; i++) {
		cin >> g;
		int tmp = Find(g, parent);
		if (!tmp) break;
		else {
			ans++;
			parent[tmp] = Find(tmp - 1,parent);
			
		}
	}

	cout << ans; 
	delete[] parent;


	return 0;
}