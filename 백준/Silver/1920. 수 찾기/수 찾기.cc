#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(const vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

int main() {
    // 입출력 관련 최적화 수행
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    // 이분 탐색을 위한 정렬

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        
        if (binarySearch(numbers, query)) cout << 1 << "\n";
        else cout << 0 << "\n"; 
    }
}