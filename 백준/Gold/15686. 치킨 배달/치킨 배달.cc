#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<pair<int, int>> houses, chickens;
int n, m;
vector<bool> selected;
int result = INT_MAX;

int calculate_distance() {
    int total_dist = 0;
    for (auto& house : houses) {
        int min_dist = INT_MAX;
        for (int i = 0; i < chickens.size(); i++) {
            if (selected[i]) {
                int dist = abs(house.first - chickens[i].first) + abs(house.second - chickens[i].second);
                min_dist = min(min_dist, dist);
            }
        }
        total_dist += min_dist;
    }
    return total_dist;
}

void dfs(int idx, int cnt) {
    if (cnt == m) {
        result = min(result, calculate_distance());
        return;
    }
    if (idx == chickens.size()) return;

    selected[idx] = true;
    dfs(idx + 1, cnt + 1);
    selected[idx] = false;
    dfs(idx + 1, cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) houses.emplace_back(i, j);
            else if (val == 2) chickens.emplace_back(i, j);
        }
    }
    selected.resize(chickens.size(), false);
    dfs(0, 0);
    cout << result << '\n';
    return 0;
}
