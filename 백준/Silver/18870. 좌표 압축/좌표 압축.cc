#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 벡터에 좌표 저장
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    // 중복 제거 및 정렬
    set<int> sortedX(X.begin(), X.end());

    map<int, int> compression;
    int compressed = 0;
    for (int x : sortedX) {
        compression[x] = compressed++;
    }

    for (int x : X) {
        cout << compression[x] << ' ';
    }
}
