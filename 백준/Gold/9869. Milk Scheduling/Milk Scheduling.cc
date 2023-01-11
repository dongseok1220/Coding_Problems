#include<iostream>
#include <algorithm>
#include <vector>
using namespace std; 


int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> job; 

	int g, d; 
	int d_max = 0;
	for (int i = 0; i < N; i++) {
		cin >> g >> d;
		job.push_back(pair<int, int>(g, d));
		if (d_max < d) d_max = d; 
	}
	sort(job.begin(), job.end(), greater<>()); // g 기준으로 정렬 

	int* arr = new int[d_max];

	int ans = 0; 

	for (int i = 0; i < d_max; i++) {
		arr[i] = 0; 
	}

	for (int i = 0; i < N; i++) {
		int tmp = job[i].second-1; // 마감일 

		if (arr[tmp] == 0) {
			arr[tmp] = job[i].first;
			ans += arr[tmp]; 
		}
		else {
			for (int j = tmp-1; j >=0; j--) {
				if (arr[j] == 0) {
					arr[j] = job[i].first;
					ans += arr[j];
					break;
				}
			}
		}
	}
	
	cout << ans; 

	delete[] arr; 
	return 0;
}