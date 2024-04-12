#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, int count, vector<int>& arr, vector<bool>& visited) {
    // m개를 모두 선택한 경우 출력
    if (count == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[count] = i;
            dfs(n, m, count + 1, arr, visited);
            visited[i] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(m);
    vector<bool> visited(n + 1);
    dfs(n, m, 0, arr, visited);
}
