#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// 지나간 점 저장할 맵
map<pair<int, int>, bool> visited;

// 지나간 선 저장할 맵
map<pair<pair<int, int>, pair<int, int>>, bool> edge;

int solution(vector<int> arrows) {
    int answer = 0;
    
    // 현재 위치
    pair<int, int> cur = {0, 0};
    visited[cur] = true;

    for (int arrow : arrows) {
        // 문제의 특성을 두 배로 확장해 도형의 외곽을 더 정확하게 추적
        for (int i = 0; i < 2; i++) {
            pair<int, int> next = {cur.first + dy[arrow], cur.second + dx[arrow]};

            // 새로운 선이고 이미 방문한 점이라면 방이므로 answer를 증가
            if (!edge[{cur, next}] && !edge[{next, cur}]) {
                if (visited[next])
                    answer++;
            }

            visited[next] = true;
            edge[{cur, next}] = true;
            cur = next;
        }
    }

    return answer;
}