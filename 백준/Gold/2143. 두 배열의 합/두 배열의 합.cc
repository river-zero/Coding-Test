#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T;
    cin >> T;

    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    vector<long long> subA;
    vector<long long> subB;

    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            subA.push_back(sum);
        }
    }

    for (int i = 0; i < m; ++i) {
        long long sum = 0;
        for (int j = i; j < m; ++j) {
            sum += B[j];
            subB.push_back(sum);
        }
    }

    sort(subB.begin(), subB.end());

    long long result = 0;

    for (auto &sumA : subA) {
        long long target = T - sumA;
        auto low = lower_bound(subB.begin(), subB.end(), target);
        auto high = upper_bound(subB.begin(), subB.end(), target);
        result += (high - low);
    }

    cout << result << '\n';

    return 0;
}
