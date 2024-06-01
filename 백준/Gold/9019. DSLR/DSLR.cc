#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX = 10000;

int visited[MAX];
string path[MAX];

string bfs(int start, int target) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num == target) {
            return path[num];
        }

        // D 연산
        int next = (num * 2) % MAX;
        if (!visited[next]) {
            q.push(next);
            visited[next] = 1;
            path[next] = path[num] + "D";
        }

        // S 연산
        next = (num - 1 + MAX) % MAX;
        if (!visited[next]) {
            q.push(next);
            visited[next] = 1;
            path[next] = path[num] + "S";
        }

        // L 연산
        next = (num % 1000) * 10 + (num / 1000);
        if (!visited[next]) {
            q.push(next);
            visited[next] = 1;
            path[next] = path[num] + "L";
        }

        // R 연산
        next = (num / 10) + (num % 10) * 1000;
        if (!visited[next]) {
            q.push(next);
            visited[next] = 1;
            path[next] = path[num] + "R";
        }
    }

    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        fill(visited, visited + MAX, 0);
        fill(path, path + MAX, "");

        string result = bfs(A, B);
        cout << result << '\n';
    }

    return 0;
}