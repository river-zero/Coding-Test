#include <iostream>
#include <vector>
using namespace std;

int find_parent(vector<int>& parent, int x) {
    if (x != parent[x])
        return parent[x] = find_parent(parent, parent[x]);
    return parent[x];
}

void merge_group(vector<int>& parent, int x, int y) {
    int px = find_parent(parent, x);
    int py = find_parent(parent, y);
    if (px != py) {
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int know_truth;
    cin >> know_truth;

    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < know_truth; i++) {
        int person;
        cin >> person;
        parent[person] = 0;
    }

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int party_size;
        cin >> party_size;
        parties[i].resize(party_size);
        for (int j = 0; j < party_size; j++) {
            cin >> parties[i][j];
            if (j > 0)
                merge_group(parent, parties[i][j - 1], parties[i][j]);
        }
    }

    int answer = m;
    for (int i = 0; i < m; i++) {
        bool has_truth = false;
        for (int j = 0; j < parties[i].size(); j++) {
            if (find_parent(parent, parties[i][j]) == 0) {
                has_truth = true;
                break;
            }
        }
        if (has_truth)
            answer--;
    }

    cout << answer << endl;
    return 0;
}