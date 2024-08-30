#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_CARD = 4000001;
vector<int> parents(MAX_CARD);

int findParent(int x) {
    if (parents[x] == x) return x;
    return parents[x] = findParent(parents[x]); 
}

void unionParents(int a, int b) {
    int rootA = findParent(a);
    int rootB = findParent(b);
    if (rootA != rootB) {
        parents[rootA] = rootB; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> cards(M);
    for (int i = 0; i < M; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    for (int i = 0; i < MAX_CARD; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < K; i++) {
        int query;
        cin >> query;
        int index = lower_bound(cards.begin(), cards.end(), query + 1) - cards.begin();
        if (index == M) {  
            continue;
        }
        int found = findParent(cards[index]);
        cout << found << "\n";
        if (found + 1 < MAX_CARD) {
            unionParents(found, found + 1);
        }
    }

    return 0;
}
