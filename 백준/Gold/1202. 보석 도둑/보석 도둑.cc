#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Jewel {
    int weight;
    int value;
};

bool cmp(Jewel a, Jewel b) {
    return a.weight < b.weight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Jewel> jewels(n);
    vector<int> bags(k);

    for (int i = 0; i < n; i++) {
        cin >> jewels[i].weight >> jewels[i].value;
    }

    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }

    // 보석과 가방을 각각 무게 기준으로 정렬
    sort(jewels.begin(), jewels.end(), cmp);
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long totalValue = 0;
    int jewelIndex = 0;

    // 가방을 순회하면서 보석을 선택
    for (int i = 0; i < k; i++) {
        // 현재 가방에 넣을 수 있는 보석을 모두 pq에 넣음
        while (jewelIndex < n && jewels[jewelIndex].weight <= bags[i]) {
            pq.push(jewels[jewelIndex].value);
            jewelIndex++;
        }

        // pq가 비어 있지 않으면 가장 가치가 높은 보석을 선택
        if (!pq.empty()) {
            totalValue += pq.top();
            pq.pop();
        }
    }

    cout << totalValue << "\n";

    return 0;
}
