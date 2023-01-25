#include<iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> job; 

	int time, dead; 
	for (int i = 0; i < N; i++) {
		cin >> time >> dead;
		job.push_back(pair<int, int>(dead, time));
	}
	sort(job.begin(), job.end()); // dead라인을 기준으로 정렬 

	int ans = job[N-1].first - job[N-1].second;
	for (int i = N-2; i>=0; i--) {
		if (ans > job[i].first)
			ans = job[i].first - job[i].second;
		else ans -= job[i].second;
	}
	
	cout << (ans >= 0 ? ans : -1) ;
	return 0;
}