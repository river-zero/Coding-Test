#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int current_sum = 0;
    int min_length = INT_MAX;

    while (end < N) {
        // 윈도우의 끝을 확장하여 합을 증가
        current_sum += arr[end];
        end++;

        // 합이 S 이상일 때 시작점을 이동하여 윈도우를 축소
        while (current_sum >= S) {
            min_length = min(min_length, end - start);
            current_sum -= arr[start];
            start++;
        }
    }

    if (min_length == INT_MAX) {
        cout << 0 << '\n';
    } else {
        cout << min_length << '\n';
    }

    return 0;
}
