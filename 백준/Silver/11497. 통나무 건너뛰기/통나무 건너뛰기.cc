#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> logs(n);
        for (int i = 0; i < n; i++) {
            cin >> logs[i];
        }
        
        sort(logs.begin(), logs.end());

        int max_diff = 0;
        for (int i = 2; i < n; i++) {
            max_diff = max(max_diff, logs[i] - logs[i - 2]);
        }
        cout << max_diff << '\n';
    }
}
