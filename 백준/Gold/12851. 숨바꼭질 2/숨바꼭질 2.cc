#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

int main() {
    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << "0\n1\n";
        return 0;
    }

    vector<int> dist(MAX, -1); // 각 위치까지의 최단 시간
    vector<int> ways(MAX, 0);  // 각 위치까지의 방법의 수

    queue<int> q;
    q.push(N);
    dist[N] = 0;
    ways[N] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next < 0 || next >= MAX) continue;

            if (dist[next] == -1) { // 처음 방문하는 경우
                dist[next] = dist[curr] + 1;
                ways[next] = ways[curr];
                q.push(next);
            } else if (dist[next] == dist[curr] + 1) { // 같은 최단 거리로 방문하는 경우
                ways[next] += ways[curr];
            }
        }
    }

    cout << dist[K] << '\n';
    cout << ways[K] << '\n';

    return 0;
}
