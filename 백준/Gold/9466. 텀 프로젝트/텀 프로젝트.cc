#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100001;
int n, student[MAX], visited[MAX], finished[MAX];
int cycleCount;  

void dfs(int current) {
    visited[current] = true;
    int next = student[current];
    
    if (!visited[next]) {
        dfs(next);
    } else {
        if (!finished[next]) {
            // 사이클을 형성하는 모든 노드를 찾아 카운트
            for (int i = next; i != current; i = student[i]) {
                cycleCount++;
            }
            cycleCount++; 
            // 현재 노드도 카운트
        }
    }
    finished[current] = true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        cycleCount = 0;

        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << n - cycleCount << '\n'; 
    }
    return 0;
}
