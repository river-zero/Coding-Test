#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1'000'000'007;
int D;
vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int size = A.size();
    vector<vector<long long>> C(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<long long>> power(vector<vector<long long>>& A, int exp) {
    int size = A.size();
    vector<vector<long long>> result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++) result[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, A);
        A = multiply(A, A);
        exp /= 2;
    }
    return result;
}

int main() {
    cin >> D;
    vector<vector<long long>> graph = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    vector<vector<long long>> result = power(graph, D);
    cout << result[0][0] << '\n'; 
    return 0;
}
