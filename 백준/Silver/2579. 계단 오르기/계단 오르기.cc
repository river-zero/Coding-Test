#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_STAIRS = 300;

int N;
int score[MAX_STAIRS + 1];
int dp[MAX_STAIRS + 1];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
    }

    cout << dp[N] << endl;

    return 0;
}