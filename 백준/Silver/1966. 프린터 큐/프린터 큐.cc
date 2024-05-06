#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        vector<int> priorities;

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({i, priority});
            priorities.push_back(priority);
        }

        sort(priorities.begin(), priorities.end(), greater<int>());

        int count = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int priority = q.front().second;
            q.pop();

            if (priority == priorities[count]) {
                count++;
                if (index == M) {
                    cout << count << '\n';
                    break;
                }
            } else {
                q.push({index, priority});
            }
        }
    }
}