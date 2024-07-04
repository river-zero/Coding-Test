#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected;
vector<bool> used;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            selected[depth] = numbers[i];
            used[i] = true;
            dfs(depth + 1);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    numbers.resize(N);
    selected.resize(M);
    used.resize(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    dfs(0);

    return 0;
}
