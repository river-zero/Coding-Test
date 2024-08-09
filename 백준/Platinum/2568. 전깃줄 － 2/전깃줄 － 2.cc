#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(), lines.end());

    vector<int> dp, prev(n, -1), lis_index;
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), lines[i].second);
        int idx = it - dp.begin();
        if (it == dp.end()) {
            dp.push_back(lines[i].second);
            indices[idx] = i;
        } else {
            *it = lines[i].second;
            indices[idx] = i;
        }
        prev[i] = idx > 0 ? indices[idx - 1] : -1;
    }

    int lis_end = indices[dp.size() - 1];
    for (int i = lis_end; i != -1; i = prev[i]) {
        lis_index.push_back(i);
    }
    reverse(lis_index.begin(), lis_index.end());

    cout << n - dp.size() << "\n";
    int lis_pos = 0;
    for (int i = 0; i < n; ++i) {
        if (lis_pos < lis_index.size() && lis_index[lis_pos] == i) {
            ++lis_pos;
            continue;
        }
        cout << lines[i].first << "\n";
    }

    return 0;
}
