#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    unordered_map<int, int> AB;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[A[i] + B[j]]++;
        }
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sumCD = C[i] + D[j];
            if (AB.count(-sumCD)) {
                count += AB[-sumCD];
            }
        }
    }

    cout << count << '\n';
    return 0;
}
