#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    vector<int> dp(n, 1);

    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (seq[i] > seq[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int lis_length = *max_element(dp.begin(), dp.end());
    cout << lis_length << '\n';

    return 0;
}
