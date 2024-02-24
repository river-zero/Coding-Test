#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    vector<pair<int, int>> ans;
    for (int T = 0; T < t; T++) {
        cin >> n;
        
        int dp[2][41];
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 1;
 
        for (int i = 2; i <= n; i++){
            dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
            dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
        }
 
        ans.push_back(make_pair(dp[0][n], dp[1][n]));
    }
 
    for (int i = 0; i < ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}