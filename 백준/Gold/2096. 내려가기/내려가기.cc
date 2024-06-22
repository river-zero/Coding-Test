#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max_dp[3] = {0}, min_dp[3] = {0};
    int temp_max[3], temp_min[3];

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        temp_max[0] = a + max(max_dp[0], max_dp[1]);
        temp_max[1] = b + max({max_dp[0], max_dp[1], max_dp[2]});
        temp_max[2] = c + max(max_dp[1], max_dp[2]);

        temp_min[0] = a + min(min_dp[0], min_dp[1]);
        temp_min[1] = b + min({min_dp[0], min_dp[1], min_dp[2]});
        temp_min[2] = c + min(min_dp[1], min_dp[2]);

        copy(begin(temp_max), end(temp_max), begin(max_dp));
        copy(begin(temp_min), end(temp_min), begin(min_dp));
    }

    int max_result = max({max_dp[0], max_dp[1], max_dp[2]});
    int min_result = min({min_dp[0], min_dp[1], min_dp[2]});

    cout << max_result << " " << min_result << '\n';

    return 0;
}
