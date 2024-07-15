#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int m, int depth, vector<int>& sequence) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = (depth == 0) ? 1 : sequence[depth - 1]; i <= n; i++) {
        sequence[depth] = i;
        dfs(n, m, depth + 1, sequence);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sequence(m);
    dfs(n, m, 0, sequence);
    return 0;
}
