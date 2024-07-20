#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    // 팰린드롬 여부 저장
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // 모든 부분 문자열에 대해 팰린드롬 여부 판단
    for (int i = 0; i < n; ++i) {
        isPalindrome[i][i] = true; // 길이 1
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = true; // 길이 2
        }
    }
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true; // 길이 3 이상
            }
        }
    }

    // 최소 분할 수 계산
    vector<int> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (isPalindrome[0][i]) {
            dp[i] = 1; // 처음부터 i까지가 팰린드롬이면 분할 수는 1
        } else {
            for (int j = 0; j < i; ++j) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
