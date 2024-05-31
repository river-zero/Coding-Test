#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        multiset<int> pq;

        while (k--) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') {
                pq.insert(num);
            } else if (op == 'D') {
                if (pq.empty()) {
                    continue;
                }

                if (num == 1) {
                    auto it = pq.end();
                    it--;
                    pq.erase(it);
                } else if (num == -1) {
                    pq.erase(pq.begin());
                }
            }
        }

        if (pq.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            auto maxIt = pq.end();
            maxIt--;
            cout << *maxIt << ' ' << *pq.begin() << '\n';
        }
    }

    return 0;
}