#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    vector<int> lis;
    for (int num : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }

    cout << lis.size() << "\n";
    return 0;
}
