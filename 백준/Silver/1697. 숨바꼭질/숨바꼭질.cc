#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> visited(100001, -1);
    queue<int> q;
    visited[N] = 0;
    q.push(N);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 초기화 리스트로 가능한 다음 위치들을 한 번에 처리
        for (int next : {current - 1, current + 1, current * 2}) {
            // 범위를 벗어나거나 이미 방문한 경우 건너뜀
            if (next < 0 || next > 100000 || visited[next] != -1) continue;

            visited[next] = visited[current] + 1;
            q.push(next);
        }
    }

    cout << visited[K] << endl;
}