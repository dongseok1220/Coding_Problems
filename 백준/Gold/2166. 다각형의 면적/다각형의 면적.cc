#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip> 

using namespace std;

int N;

// 신발끈 공식
double Area(vector<pair<double,double>> points) {
    double area = 0; 

    for (int i=0; i<N; i++) {
        int j = (i+1) % N; 
        area += ((points[i].first * points[j].second) - (points[j].first * points[i].second));
    }

    return abs(area) / 2; 
}

int main() {
    cin >> N; 

    vector<pair<double,double>> points(N); 

    for (int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second; 
    }

    cout << fixed << setprecision(1) << Area(points); 

    return 0;
}
