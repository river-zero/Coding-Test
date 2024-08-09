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
    vector<int> solutions(N);
    for (int i = 0; i < N; i++) {
        cin >> solutions[i];
    }

    sort(solutions.begin(), solutions.end());
    int left = 0, right = N - 1;
    int minAbs = 2e9, ansLeft = 0, ansRight = 0;

    while (left < right) {
        int sum = solutions[left] + solutions[right];
        if (abs(sum) < minAbs) {
            minAbs = abs(sum);
            ansLeft = solutions[left];
            ansRight = solutions[right];
        }
        if (sum > 0) right--;
        else left++;
    }

    cout << ansLeft << " " << ansRight << "\n";
    return 0;
}
