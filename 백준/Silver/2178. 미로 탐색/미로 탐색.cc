#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX_SIZE = 100;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int N, M;
int maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int bfs(int startRow, int startCol) {
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    
    int distance = 1;
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (row == N - 1 && col == M - 1) {
                return distance;
            }
            
            for (int j = 0; j < 4; j++) {
                int newRow = row + dr[j];
                int newCol = col + dc[j];
                
                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M
                    && maze[newRow][newCol] && !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        
        distance++;
    }
    
    return -1;
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';
        }
    }
    
    int minDistance = bfs(0, 0);
    
    cout << minDistance << endl;
    
    return 0;
}