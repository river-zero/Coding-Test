#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, int m, int depth, vector<int>& sequence, vector<int>& nums) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (depth == 0 || sequence[depth - 1] <= nums[i]) {
            sequence[depth] = nums[i];
            dfs(n, m, depth + 1, sequence, nums);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), sequence(m);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    n = nums.size();
    dfs(n, m, 0, sequence, nums);
    return 0;
}
