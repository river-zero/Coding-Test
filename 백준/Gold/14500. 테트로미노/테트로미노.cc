#include <iostream>
using namespace std;

const int MAX = 500;

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int maxSum = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int sum, int count) {
    if (count == 4) {
        maxSum = max(maxSum, sum);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny]) {
            continue;
        }
        
        visited[nx][ny] = true;
        dfs(nx, ny, sum + board[nx][ny], count + 1);
        visited[nx][ny] = false;
    }
}

void checkExtraShape(int x, int y) {
    // ㅗ 모양
    if (x >= 1 && y >= 1 && y < M-1) {
        int sum = board[x][y] + board[x][y-1] + board[x][y+1] + board[x-1][y];
        maxSum = max(maxSum, sum);
    }
    // ㅏ 모양
    if (x >= 1 && x < N-1 && y < M-1) {
        int sum = board[x][y] + board[x+1][y] + board[x-1][y] + board[x][y+1];
        maxSum = max(maxSum, sum);
    }
    // ㅜ 모양
    if (x < N-1 && y >= 1 && y < M-1) {
        int sum = board[x][y] + board[x][y-1] + board[x][y+1] + board[x+1][y];
        maxSum = max(maxSum, sum);
    }
    // ㅓ 모양
    if (x >= 1 && x < N-1 && y >= 1) {
        int sum = board[x][y] + board[x+1][y] + board[x-1][y] + board[x][y-1];
        maxSum = max(maxSum, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, board[i][j], 1);
            visited[i][j] = false;
            checkExtraShape(i, j);
        }
    }
    
    cout << maxSum << '\n';
    
    return 0;
}