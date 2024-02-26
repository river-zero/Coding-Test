#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    
    for (int i = 1; i <= N; i++) {
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}
    
    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << dp[end] - dp[start - 1] << '\n';
    }
}