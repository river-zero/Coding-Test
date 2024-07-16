#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    queue<pair<long long, int>> q;
    q.push({A, 1});

    while (!q.empty()) {
        long long current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current == B) {
            cout << count << endl;
            return 0;
        }

        if (current * 2 <= B) {
            q.push({current * 2, count + 1});
        }
        if (current * 10 + 1 <= B) {
            q.push({current * 10 + 1, count + 1});
        }
    }

    cout << -1 << endl;
    return 0;
}
