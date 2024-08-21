#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> lis;
    vector<pair<int, int>> trace(N);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int num = arr[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int idx = it - lis.begin();
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
        trace[i] = {idx, num};
    }

    cout << lis.size() << "\n";
    
    vector<int> ans(lis.size());
    int size = lis.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (trace[i].first == size) {
            ans[size] = trace[i].second;
            size--;
        }
    }

    for (int i = 0; i < lis.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
