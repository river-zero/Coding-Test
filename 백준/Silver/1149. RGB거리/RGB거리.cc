#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cost[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i < N; i++) {
        cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
        cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
        cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
    }

    int result = min(min(cost[N - 1][0], cost[N - 1][1]), cost[N - 1][2]);
    
    cout << result << endl;
}
