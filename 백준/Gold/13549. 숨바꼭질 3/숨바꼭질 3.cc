#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> visited(100001, -1);
    deque<int> dq;
    
    visited[N] = 0;
    dq.push_back(N);
    
    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        if (current == K) {
            cout << visited[current] << '\n';
            return 0;
        }

        int next_positions[3] = {current * 2, current - 1, current + 1};

        for (int i = 0; i < 3; ++i) {
            int next = next_positions[i];

            if (next < 0 || next > 100000 || visited[next] != -1) continue;

            if (i == 0) { // 순간 이동인 경우 (0초)
                visited[next] = visited[current];
                dq.push_front(next);
            } else { // 걷는 경우 (+1초)
                visited[next] = visited[current] + 1;
                dq.push_back(next);
            }
        }
    }

    return 0;
}
