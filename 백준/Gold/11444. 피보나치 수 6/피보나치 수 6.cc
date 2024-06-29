#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

typedef vector<vector<long long>> matrix;

// 행렬 곱셈 함수
matrix multiply(matrix &a, matrix &b) {
    matrix result(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

// 행렬 제곱 함수
matrix power(matrix a, long long n) {
    matrix result = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, a);
        }
        a = multiply(a, a);
        n /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    matrix fibMatrix = {{1, 1}, {1, 0}};

    if (n == 0) {
        cout << 0 << endl;
    } else {
        matrix result = power(fibMatrix, n - 1);
        cout << result[0][0] << endl;
    }

    return 0;
}
