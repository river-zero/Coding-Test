#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

struct Edge {
    int s, e, t;
};

bool bellmanFord(int n, const vector<Edge>& edges) {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (const auto& edge : edges) {
            int s = edge.s;
            int e = edge.e;
            int t = edge.t;

            if (dist[s] != INF && dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;
                if (i == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        for (int i = 0; i < M; ++i) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({ S, E, T });
            edges.push_back({ E, S, T });
        }

        for (int i = 0; i < W; ++i) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({ S, E, -T });
        }

        bool hasNegativeCycle = false;

        for (int i = 1; i <= N; ++i) {
            vector<int> dist(N + 1, INF);
            dist[i] = 0;
            bool updated = false;

            for (int j = 0; j < N; ++j) {
                updated = false;
                for (const auto& edge : edges) {
                    int s = edge.s;
                    int e = edge.e;
                    int t = edge.t;

                    if (dist[s] != INF && dist[s] + t < dist[e]) {
                        dist[e] = dist[s] + t;
                        updated = true;
                    }
                }
                if (!updated) break;
            }

            if (updated) {
                hasNegativeCycle = true;
                break;
            }
        }

        cout << (hasNegativeCycle ? "YES\n" : "NO\n");
    }

    return 0;
}
