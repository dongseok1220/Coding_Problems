#include<iostream>
#include <algorithm>
#include <vector>
using namespace std; 

typedef struct time {
	int s;
	int f; 
}time; 

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> S; 

	int s, f; 
	for (int i = 0; i < N; i++) {
		cin >> s >> f;
		S.push_back(pair<int, int>(f, s));
	}
	sort(S.begin(), S.end());

	int ans = 1; 
	int k = 0; 

	for (int j = 1; j < N; j++) {
	
		if (S[j].second >= S[k].first) {
			k = j;
			//cout << k << " "; 
			ans += 1; 
		}
	}

	cout << ans; 
	return 0;
}