#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;

int N, M;
vector<int> ladder(MAX + 1, 0);
vector<int> snake(MAX + 1, 0);
vector<int> dist(MAX + 1, -1);

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == 100) {
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int next = curr + i;

            if (next > 100) {
                continue;
            }

            if (ladder[next] != 0) {
                next = ladder[next];
            }

            if (snake[next] != 0) {
                next = snake[next];
            }

            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    bfs();

    cout << dist[100] << '\n';

    return 0;
}