#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
vector<long long> trees;

bool canCutTrees(long long height) {
    long long totalLength = 0;
    for (long long tree : trees) {
        if (tree > height) {
            totalLength += tree - height;
        }
    }
    return totalLength >= M;
}

long long binarySearch(long long low, long long high) {
    long long result = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (canCutTrees(mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        long long height;
        cin >> height;
        trees.push_back(height);
    }

    long long maxHeight = *max_element(trees.begin(), trees.end());
    long long cutHeight = binarySearch(0, maxHeight);

    cout << cutHeight << endl;

    return 0;
}