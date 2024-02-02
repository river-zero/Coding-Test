#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();

    // 첫 번째 집을 털 경우
    vector<int> dp1(n);
    dp1[0] = money[0];
    dp1[1] = dp1[0]; 
    // 첫 번째 집을 털면 두 번째 집은 털지 못함

    for (int i = 2; i < n - 1; i++) { 
        // 첫 번째 집을 털면 마지막 집은 털지 못함
        
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    }

    // 첫 번째 집을 털지 않는 경우
    vector<int> dp2(n);
    dp2[0] = 0;
    dp2[1] = money[1];

    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}