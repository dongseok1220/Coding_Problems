#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

const int MOD = 1000000007;
const int s = 2; 

matrix matMul(matrix &A, matrix &B, int mod) {
    matrix C(s, vector<long long>(s));
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            for (int k = 0; k < s; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

matrix matPow(matrix A, long long n, int mod) {
    matrix result(s, vector<long long>(s));
    for (int i = 0; i < s; ++i)
        result[i][i] = 1; // 단위 행렬로 초기화

    while (n > 0) {
        if (n % 2 == 1)
            result = matMul(result, A, mod);
        A = matMul(A, A, mod);
        n /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    matrix A = {{1, 1}, {1, 0}};
    
    if (n == 0) {
        cout << 0 << endl;
    } else {
        matrix result = matPow(A, n - 1, MOD);
        cout << result[0][0] << endl; // F(n) 값
    }

    return 0;
}


