#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> solutions(N);
    for (int i = 0; i < N; i++) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());
    long long minAbs = 3e9 + 1;
    long long ans1, ans2, ans3;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        while (left < right) {
            long long sum = solutions[i] + solutions[left] + solutions[right];
            if (abs(sum) < minAbs) {
                minAbs = abs(sum);
                ans1 = solutions[i];
                ans2 = solutions[left];
                ans3 = solutions[right];
            }
            if (sum > 0) right--;
            else left++;
        }
    }

    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    return 0;
}
