#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 25;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int N;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int cnt;

void dfs(int r, int c) {
    visited[r][c] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N && map[nr][nc] && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    vector<int> complexSizes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                complexSizes.push_back(cnt);
            }
        }
    }

    sort(complexSizes.begin(), complexSizes.end());

    cout << complexSizes.size() << endl;
    for (int size : complexSizes) {
        cout << size << endl;
    }

    return 0;
}