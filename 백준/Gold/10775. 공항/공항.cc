#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);  // 경로 압축
}

bool unionGate(int x) {
    int root = find(x);
    if (root == 0) return false;  // 더 이상 도킹할 게이트가 없는 경우
    parent[root] = root - 1;  // root 게이트를 사용했으니 그 다음 번호를 부모로 설정
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, P, g, answer = 0;
    cin >> G >> P;
    parent.resize(G + 1);

    // 모든 게이트를 자기 자신으로 초기화
    for (int i = 1; i <= G; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < P; i++) {
        cin >> g;
        if (!unionGate(g)) break;  // 게이트 도킹 시도, 실패하면 중단
        answer++;  // 성공적으로 도킹
    }

    cout << answer << "\n";
    return 0;
}
