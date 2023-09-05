#include <iostream>
#include <limits.h> // INT_MIN을 사용하기 위해

using namespace std;

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_sub = INT_MIN;  // 가장 작은 정수로 초기화
    int max_tail = 0;

    for (int i = 0; i < n; i++) {
        max_tail = max(arr[i], max_tail + arr[i]);  // 0 대신 arr[i]와 비교
        max_sub = max(max_sub, max_tail);
    }

    cout << max_sub;
    delete[] arr;

    return 0;
}
