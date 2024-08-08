#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int dp[100001][5][5];
int moves[100001];
int N = 0;

int energy(int from, int to) {
    if (from == to) return 1;
    if (from == 0) return 2;
    if ((from == 1 && to == 3) || (from == 3 && to == 1) ||
        (from == 2 && to == 4) || (from == 4 && to == 2)) return 4;
    if ((from == 1 && to == 2) || (from == 2 && to == 1) ||
        (from == 2 && to == 3) || (from == 3 && to == 2) ||
        (from == 3 && to == 4) || (from == 4 && to == 3) ||
        (from == 4 && to == 1) || (from == 1 && to == 4)) return 3;
    return 1; // same spot, already handled above
}

int solve(int step, int left, int right) {
    if (moves[step] == 0) return 0; // end of input
    int& ret = dp[step][left][right];
    if (ret != -1) return ret;
    int next = moves[step];
    ret = INF;
    if (next != right) {
        ret = min(ret, solve(step + 1, next, right) + energy(left, next));
    }
    if (next != left) {
        ret = min(ret, solve(step + 1, left, next) + energy(right, next));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    int input;
    while (cin >> input && input != 0) {
        moves[N++] = input;
    }

    cout << solve(0, 0, 0) << '\n';

    return 0;
}
