#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, int start, int count, vector<int>& arr) {
    if (count == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[count] = i;
        dfs(n, m, i + 1, count + 1, arr);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    dfs(n, m, 1, 0, arr);
}
