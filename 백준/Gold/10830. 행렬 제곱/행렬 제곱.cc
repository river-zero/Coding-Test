#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
typedef vector<vector<int>> Matrix;

Matrix multiply(Matrix &A, Matrix &B, int N) {
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matrixPower(Matrix &A, long long B, int N) {
    if (B == 1) {
        return A;
    }

    Matrix half = matrixPower(A, B / 2, N);
    Matrix halfSquared = multiply(half, half, N);

    if (B % 2 == 0) {
        return halfSquared;
    } else {
        return multiply(halfSquared, A, N);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long B;
    cin >> N >> B;

    Matrix A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            A[i][j] %= MOD;
        }
    }

    Matrix result = matrixPower(A, B, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
