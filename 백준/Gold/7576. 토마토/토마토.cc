#include <iostream>
#include <queue>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    // 초기 상자 정보 입력
    vector<vector<int>> box(N, vector<int>(M));
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            
            // 익은 토마토라면 큐에 삽입
            if (box[i][j] == 1) q.push({i, j});
        }
    }
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int days = -1;
    
    while (!q.empty()) {
        int size = q.size();
        
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // 상자 내부에 존재하고 익지 않은 토마토인 경우
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && box[nx][ny] == 0) {
                    box[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        days++; 
    }
    
    // 상자에 익지 않은 토마토가 있는지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) days = -1;
        }
    }

    cout << days << endl;
}