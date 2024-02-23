#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());
    
    // 투 포인터 알고리즘으로 효율적 탐색
    int maxSum = 0;
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;
        
        while (left < right) {
            int sum = cards[i] + cards[left] + cards[right];
            
            if (sum <= M) {
                maxSum = max(maxSum, sum);
                left++;
            } else {
                right--;
            }
        }
    }
    
    cout << maxSum;
}